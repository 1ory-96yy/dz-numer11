#pragma once

#include <stdexcept>

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

    void resize(int newSize);

public:
    Array(int initialCapacity = 10, int grow = 5);
    ~Array();
    T& operator[](int index);
    void Add(const T& item);
    int GetSize() const;
    void SetSize(int newSize, int newGrow = 1);
};

template <typename T>
Array<T>::Array(int initialCapacity, int grow) : size(0), capacity(initialCapacity), grow(grow) {
    data = new T[capacity];
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
void Array<T>::Add(const T& item) {
    if (size >= capacity) {
        resize(capacity + grow);
    }
    data[size++] = item;
}

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
void Array<T>::SetSize(int newSize, int newGrow) {
    if (newSize <= 0 || newGrow <= 0) {
        throw std::invalid_argument("New size and grow must be positive");
    }
    if (newSize > capacity) {
        resize(newSize);
    }
    grow = newGrow;
}

template <typename T>
void Array<T>::resize(int newSize) {
    T* newData = new T[newSize];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newSize;
}
