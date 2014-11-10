#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include "Row.h"
#include "Row.cpp"

using namespace std;

void matrix_testing();

int main()
{
    matrix_testing();
    return 0;
}
void matrix_testing()
{
    Matrix a(2, 2 ,4.0), b(2, 2, 3.0), c(2, 3, 5.0);
    cout << "TEST 1:" << endl;
    cout << "Operation == :"
    << (a == a && !(a == b) ? "OK": "Failed") << endl;
    cout << "Operation + :"
    << (a + b == Matrix(2, 2, 7.0) ? "OK": "Failed") << endl;
    cout << "Operation - :"
    << (a - b == Matrix(2, 2, 1.0) ? "OK": "Failed") << endl;
    cout << "Operation * :"
    << (a * b == Matrix(2, 2, 24) ? "OK": "Failed") << endl;
    cout << "Transpose :"
    << (c.transpose() == Matrix(3, 2, 5.0) ? "OK": "Failed") << endl;
}
