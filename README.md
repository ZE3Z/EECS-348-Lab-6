# EECS-348-Lab-6

This code is a comprehensive example of basic matrix operations in C++. It includes functionality to read matrices from a file, perform arithmetic operations (addition, subtraction, multiplication), update elements, find the maximum value within a matrix, transpose matrices, and print matrices in a readable format. Here's a detailed breakdown of its capabilities and workflow:

Global Definition: It starts with defining a global constant N, which represents the dimensions of the square matrices involved in all operations. This value is set to 3, making the matrices 3x3, but can be adjusted as needed.

Reading Matrices from a File: The readMatrixFromFile function reads matrix data from a specified file, storing the data in a 2D array. It takes the file name, the matrix to fill, and a starting line number as parameters, allowing it to skip to different parts of the file for reading multiple matrices.

Printing Matrices: The printMatrix function prints a given matrix in a tabulated format, making it easy to visualize the matrix's contents.

Arithmetic Operations:

addMatrices adds two matrices together and stores the result in a third matrix.
subtractMatrices subtracts the second matrix from the first, storing the result in another matrix.
multiplyMatrices multiplies two matrices, again storing the result in a separate matrix.
Matrix Manipulation:

updateElement updates a specific element in a matrix to a new value, given its row and column indices.
findMaxValue finds and returns the maximum value in a given matrix.
transposeMatrix transposes a matrix, switching rows with columns, and stores the result in another matrix.
Main Workflow: In the main function, the program:

Initializes three matrices: matrix1, matrix2, and resultMatrix.
Reads two matrices from a file named matrix_input.txt, using predefined starting lines (0 for the first matrix and N for the second, assuming a straightforward sequential format in the file).
Performs and displays the results of various operations between matrix1 and matrix2, including addition, subtraction, multiplication, and the transposition of matrix1.
Updates an element in matrix1 and displays the modified matrix.
Finds and displays the maximum value in matrix1.

This code serves as a basic framework for performing and demonstrating simple matrix operations, suitable for educational purposes or as a starting point for more complex matrix-based computations.
