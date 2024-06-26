#include <iostream>
namespace ContList{

template<typename T>
struct Node{
    Node* next;
    Node* prev;
    T data;
    Node(const T& value): data(value), next(nullptr), prev(nullptr) {};
    Node(): data(0), next(nullptr), prev(nullptr) {};
};

template<typename T>
class ContainerList
{
    public:
    ContainerList(): head(nullptr), tail(nullptr), size(0) {};

    void push_back(const T& value) {
        Node<T>* new_node = new Node<T>(value);
        new_node->data = value;
        new_node->next = nullptr;
        // if there is no nodes at all
        if(size == 0)
        {
            head = new_node;
            tail = new_node;
        }
        // if some nodes exist
        if(tail != nullptr)
        {
            tail->next = new_node;
            new_node->prev = tail;
        }        
        tail = new_node;
        size += 1;
    }

    void push_front(const T& value)
    {
        Node<T>* new_node = new Node<T>(value);
        new_node->next = nullptr;
        new_node->data = value;
        // if there is no nodes at all
        if(size == 0)
        {
            head = new_node;
            tail = new_node;
        }
        if(head != nullptr)
        {
            new_node->next = head;
            head->prev = new_node;
        }
        head = new_node;
        size += 1;
    }
        
        size_t GetSize()
        {
            return this->size;
        }

        const T& operator[](int index) const
        {
            if(index >= size || index < 0 || size == 0)
            {
                throw std::out_of_range("Index is out of range or no nodes in container");
            }
            else{
                Node<T>* current = head;
                for(int i = 0; i < index; i++)
                {
                    current = current->next;
                }
                return current->data;
            }
            
        }

        void erase(int index)
        {
            if(index >= size || index < 0)
            {
                std::out_of_range("Index is out of range");
            }
            Node<T>* current = head;
            for(int i = 0; i < index; i++)
            {
                current = current->next;
            }
            if(current->prev)
            {
                current->prev->next = current->next;
            }
            if(current->next)
            {
                current->next->prev = current->prev;
            }
            delete[] current;
            size--;
        }

        void insert(size_t index, const T& value)
        {
            if(index >= size || index < 0)
            {
                throw std::out_of_range("The index is out of range");
            }
            if(index == 0)
            {
                push_front(value);
            }
            if(index == size)
            {
                push_back(value);
            }
            Node<T>* new_node = new Node<T>(value);
            Node<T>* current = head;
            for(auto i = 0; i < index; i++)
            {
                current = current->next;
            }
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
            size++;
        }

        ContainerList(ContainerList&& other) noexcept {
            clear();
            head = other.head;
            tail = othe.tail;
            size = othe.size;
            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }

        ContainerList& operator=(ContainerList&& other) noexcept {
            if(this != &other)
            {
                clear();
                head = other.head;
                tail = othe.tail;
                size = othe.size;
                other.head = nullptr;
                other.tail = nullptr;
                other.size = 0;
            }
            return *this;
        }

        void clear()
        {
            Node<T>* current = head;
            while (current != nullptr)
            {
                Node<T>* next_node = current->next;
                delete current;
                current = next_node;
            }
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

};

template<typename T>
std::ostream& operator<<(std::ostream& os, ContainerList<T>& cont)
{
    for(auto i = 0; i < cont.GetSize(); i++)
    {
        os << cont[i] << " ";
    }
    return os;
}
}