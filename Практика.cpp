//Занятие 06.03 дисциплина "Основы параллельных вычислений"
//Вычисление суммы элементов массива 

#include <iostream>
#include <omp.h>
#include <thread>

using namespace std;

int main() {
    int arraySize;
    std::cout << "Size: ";
    std::cin >> arraySize;

    int* arr = new int[arraySize];

    int numThreads = std::thread::hardware_concurrency(); 
    std::cout << "Threads: " << numThreads << std::endl;

    omp_set_num_threads(numThreads); 

        for (int i = 0; i < arraySize; i++) {
            arr[i] = rand() % 100;
        }

        std::cout << "Random array: ";
        for (int i = 0; i < arraySize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        int sum = 0;

#pragma omp parallel for 
        for (int i = 0; i < arraySize; i++) {
            sum += arr[i];
        }
        std::cout << "Sum: " << sum << std::endl;

        delete[] arr; 
        return 0;
    }


