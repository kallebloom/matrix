#ifndef MATRIX_H
#define MATRIX_H

#include "Row.h"
#include <iostream>

class Matrix
{
private:
    //указатель на строку матрицы
    Row *_matrix;
    //число столбцов
    int _cols;
    //число строк
    int _rows;

public:
    //конструктор с параметрами
    //rows-число строк (по умолчанию rows=1)
    //cols-число столбцов(по умолчанию cols=1)
    //fill-заполнитель матрицы(по умолчанию fill=0)
    Matrix(int = 1, int = 1, double = 0.0);
    //конструктор копирования
    Matrix(const Matrix &);
    //деструктор
    ~Matrix();
    //функция определения размеров матрицы
    int size() const;
    //функция изменения размеров матрицы
    void resize(int = 1, double = 0.0);
    //функция транспонирования
    Matrix transpose() const;
    //перегрузка оператора доступа к определенной строке матрицы
    Row &operator[](int);
    //перегрузка оператора доступа к определенной строке матрицы(константный)
    const Row &operator[](int) const;
    //перегрузка операторов потоков ввода и вывода
    friend std::istream &operator>>(std::istream &, Matrix &);
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
    //перегрузка оператора сложения
    Matrix operator+(const Matrix &) const;
    const Matrix &operator+=(const Matrix &);
    //перегрузка оператора вычитания
    Matrix operator-(const Matrix &) const;
    const Matrix &operator-=(const Matrix &);
    //перегрузка оператора умножения
    Matrix operator*(const Matrix &) const;
    const Matrix &operator*=(const Matrix &);
    friend Matrix operator*(const Matrix &, const double);
    friend const Matrix &operator*=(Matrix &, const double);
    friend Matrix operator*(const double, const Matrix &);
    //перегрузка операторов сравнения
    bool operator==(const Matrix &) const;
    bool operator!=(const Matrix &) const;
    //перегрузка оператора присваивания
    const Matrix &operator=(const Matrix &);
};

#endif
