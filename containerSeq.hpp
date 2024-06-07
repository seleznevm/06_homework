#include <iostream>

template<typename T>
class ContainerSeq
{
    public:
        ContainerSeq(): _data(nullptr), _size(0) {}
    
        ~ContainerSeq() {delete[] _data;}
    
        void push_back(const T& value) {
            T* new_data = new T[_size + 1];
            for (size_t i = 0; i < _size; i++)
            {   
                new_data[i] = _data[i];
            }
            new_data[_size] = value;
            delete[] _data;
            _data = new_data;
            _size++;
        }

        void push_front(const T& value)
        {
            T* new_data = new T[_size + 1];
            for(size_t i = 1; i < _size + 1; i++)
                {
                    new_data[i] = _data[i - 1];
                }
                new_data[0] = value;
                delete[] _data;
                _data = new_data;
                _size++;
        }

        void insert(size_t index, const T& value)
        {
            if(index > _size || index < 0)
                {
                    throw std::out_of_range("Index out of range");
                }
            T* new_data = new T[_size + 1];
            for(size_t i = 0; i < index; i++)
            {
                new_data[i] = _data[i];
            }
            new_data[index] = value;
            for(size_t i = index; i < _size; i++)
            {
                new_data[i + 1] = _data[i];
            }
            delete[] _data;
            _data = new_data;
            _size++;
        }
    
    // GetSize
        size_t GetSize() const
        {
            return _size;
        }        
    // index operator []
        const T& operator[](int index) const
        {
            if(index >= _size)
            {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }
    // erase by index
        void erase(int index)
        {
            if(index >= _size || index < 0)
            {
                throw std::out_of_range("Index out of range");
            }

            T* new_data = new T[_size - 1];
            for(size_t i = 0; i < index; i++)
                {
                    new_data[i] = _data[i];
                }            
            for(size_t i = index + 1; i < _size; i++)
            {
                new_data[i - 1] = _data[i];
            }
            delete[] _data;
            _data = new_data;
            _size--;
        }

        

    private:
        T* _data;
        size_t _size;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const ContainerSeq<T>& cont)
    {
        for(auto i = 0; i < cont.GetSize(); i++)
        os << cont[i] << " ";
        return os;
    }