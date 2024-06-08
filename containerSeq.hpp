#include <iostream>

template<typename T>
class ContainerSeq
{
    public:
        ContainerSeq(): _size(0), _capacity(5) {
            T* data = new T[_capacity];
            _data = data;
        }
    
        ~ContainerSeq() {delete[] _data;}
    
        void push_back(const T& value) {
            if(_size >= _capacity)
            {
                addCapacity();
            }
            _data[_size] = value;
            _size++;
        }

        void push_front(const T& value)
        {
            if(_size >= _capacity)
            {
                addCapacity();
            }

            for(size_t i = _size; i > 0; i--)
                {
                    _data[i] = _data[i - 1];    
                }
                _data[0] = value;
                ++_size;
                }

        void insert(size_t index, const T& value)
        {
            if(index > _size || index < 0)
                {
                    throw std::out_of_range("Index out of range");
                }

            if(_size >= _capacity)
            {
                addCapacity();
            }
            // move positions starting from index to 1
            for(size_t i = _size; i > index; i--)
            {
                _data[i] = _data[i - 1];
            }
            _data[index] = value;
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

        for (size_t i = index; i < _size - 1; ++i) {
            _data[i] = _data[i + 1];
        }
        _size--;
        }

    private:
        T* _data;
        size_t _size;
        size_t _capacity;
        void addCapacity()
        {
            _capacity *= 2;
            T* newData = new T[_capacity];
            for(auto i = 0; i < _size; i++)
            {
                newData[i] = _data[i];
            }
            delete[] _data;
            _data = newData;
        }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const ContainerSeq<T>& cont)
    {
        for(auto i = 0; i < cont.GetSize(); i++)
        os << cont[i] << " ";
        return os;
    }