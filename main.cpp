#include "1.h"
#include <iostream>

int main() {
    Array<int> arr;
    arr.SetSize(5, 5);

    for (int i = 0; i < 11; ++i) {
        arr.Add(i);
    }

    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
