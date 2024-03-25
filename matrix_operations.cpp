#include <iostream>
#include <fstream>
#include <string>

const int N = 3; // Define the size of the square matrix. Adjust as needed.

// Reads matrix data from a file and stores it in a 2D array
void readMatrixFromFile(const std::string& fileName, int matrix[N][N], int startLine) {
    std::ifstream file(fileName); // Open the file for reading
    if (!file) {
        std::cerr << "Unable to open file.\n"; // Error handling if file cannot be opened
        return;
    }
    std::string line;
    // Skip lines until reaching the start line for the second matrix
    for (int i = 0; i < startLine; ++i) {
        std::getline(file, line);
    }
    for (int i = 0; i < N; ++i) { // Iterate over rows
        for (int j = 0; j < N; ++j) { // Iterate over columns
            file >> matrix[i][j]; // Store each number in the matrix
        }
    }
}

// Prints the matrix in a formatted manner
void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) { // Loop through each row
        for (int j = 0; j < N; ++j) { // Loop through each column
            std::cout << matrix[i][j] << "\t"; // Print each element with a tab for spacing
        }
        std::cout << std::endl; // New line at the end of each row
    }
}

// Adds two matrices and stores the result in a third matrix
void addMatrices(int matrix1[N][N], int matrix2[N][N], int resultMatrix[N][N]) {
    for (int i = 0; i < N; ++i) { // Iterate over rows
        for (int j = 0; j < N; ++j) { // Iterate over columns
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j]; // Perform element-wise addition
        }
    }
}

// Subtracts the second matrix from the first and stores the result in a third matrix
void subtractMatrices(int matrix1[N][N], int matrix2[N][N], int resultMatrix[N][N]) {
    for (int i = 0; i < N; ++i) { // Iterate over rows
        for (int j = 0; j < N; ++j) { // Iterate over columns
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j]; // Perform element-wise subtraction
        }
    }
}

// Multiplies two matrices and stores the result in a third matrix
void multiplyMatrices(int matrix1[N][N], int matrix2[N][N], int resultMatrix[N][N]) {
    for (int i = 0; i < N; ++i) { // Iterate over rows of the result matrix
        for (int j = 0; j < N; ++j) { // Iterate over columns of the result matrix
            resultMatrix[i][j] = 0; // Initialize the element to 0
            for (int k = 0; k < N; ++k) { // Perform the dot product of rows and columns
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Updates an element in the matrix with a new value
void updateElement(int matrix[N][N], int row, int col, int newValue) {
    if (row >= 0 && row < N && col >= 0 && col < N) { // Validate row and column indices
        matrix[row][col] = newValue; // Update the specified element
    }
    else {
        std::cerr << "Invalid row or column index.\n"; // Error message for invalid indices
    }
}

// Finds and returns the maximum value in the matrix
int findMaxValue(int matrix[N][N]) {
    int maxValue = matrix[0][0]; // Start with the first element as the max value
    for (int i = 0; i < N; ++i) { // Iterate over rows
        for (int j = 0; j < N; ++j) { // Iterate over columns
            if (matrix[i][j] > maxValue) { // If current element is greater than max
                    maxValue = matrix[i][j]; // Update the max value
            }
        }
    }
    return maxValue; // Return the max value found in the matrix
}

// Transposes a square matrix and stores the result in a second matrix
void transposeMatrix(int matrix[N][N], int resultMatrix[N][N]) {
    for (int i = 0; i < N; ++i) { // Loop through rows
        for (int j = 0; j < N; ++j) { // Loop through columns
            resultMatrix[j][i] = matrix[i][j]; // Swap elements to transpose
        }
    }
}

int main() {
    int matrix1[N][N], matrix2[N][N], resultMatrix[N][N];

    // Read the first matrix from the file, starting at the beginning
    readMatrixFromFile("matrix_input.txt", matrix1, 0);
    // For the second matrix, assuming N lines per matrix plus one for the size, start after the first matrix
    readMatrixFromFile("matrix_input.txt", matrix2, N);

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1);

    std::cout << "\nMatrix 2:" << std::endl;
    printMatrix(matrix2);

    // Addition
    addMatrices(matrix1, matrix2, resultMatrix);
    std::cout << "\nResult of Addition:" << std::endl;
    printMatrix(resultMatrix);

    // Subtraction
    subtractMatrices(matrix1, matrix2, resultMatrix);
    std::cout << "\nResult of Subtraction:" << std::endl;
    printMatrix(resultMatrix);

    // Multiplication
    multiplyMatrices(matrix1, matrix2, resultMatrix);
    std::cout << "\nResult of Multiplication:" << std::endl;
    printMatrix(resultMatrix);

    // Transpose of Matrix 1
    transposeMatrix(matrix1, resultMatrix);
    std::cout << "\nTranspose of Matrix 1:" << std::endl;
    printMatrix(resultMatrix);

    // Updating an element in Matrix 1
    // Example: Update element at 1st row, 1st column to 100
    updateElement(matrix1, 0, 0, 100);
    std::cout << "\nMatrix 1 after update:" << std::endl;
    printMatrix(matrix1);

    // Find the max value in Matrix 1
    int maxValue = findMaxValue(matrix1);
    std::cout << "\nMax value in Matrix 1: " << maxValue << std::endl;

    return 0; // End of program
}