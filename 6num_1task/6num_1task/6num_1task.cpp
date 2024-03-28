#include <iostream>

void reverse_rows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows / 2; i++) {
        int* temp = matrix[i];
        matrix[i] = matrix[rows - i - 1];
        matrix[rows - i - 1] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int rows, cols;

    std::cout << "число строк: ";
    std::cin >> rows;

    std::cout << "число столбов: ";
    std::cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    std::cout << "Введите элемент матрицы:" << std::endl; 
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "введите элемент [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    reverse_rows(matrix, rows, cols);

    std::cout << "Результат:" << std::endl; //отрисовка матрицы резултат
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) { // очистка памяти
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
