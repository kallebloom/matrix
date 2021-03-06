#include "Row.h"
#include <iostream>

// Конструктор по-умолчанию
Row::Row():
// Устанавливаем размер по умолчанию
_size(1)
{
    // Выделяем память
    _row = new double [_size];

    // Заполняем строку нулями
    for (int i = 0; i < _size; ++i)
        _row[i] = 0.0;
}

// Конструктор с параметрами
// size - размер строки
// fill - значение, которым будет заполнена строка (по умолчанию 0)
Row::Row(int size, double fill):
// Устанавливаем размер строки
_size(size)
{
    // Выделяем память под строку
    _row = new double [_size];

    // Заполняем строку нашим значением
    for (int i = 0; i < _size; ++i)
        _row[i] = fill;
}

// Конструктор копирования
Row::Row(const Row &c):
// Устанавливаем размер строки
_size(c._size)
{
    // Выделяем память под строку
    _row = new double [_size];
    // Инициализируем элементы новой строки элементами начальной строки
    for (int i = 0; i < _size; ++i)
        _row[i] = c._row[i];
}

// Деструктор
Row::~Row()
{
    // Освобождаем память, отведённую под строку
    delete [] _row;
}

// Функция изменения размера строки
void Row::resize(int size, double fill)
{
    // Если исходный размер строки не совпадает с желаемым
    if (_size != size)
    {
        // Устанавливаем размер строки равным желаемому
        _size = size;
        // Освобождаем память из-под исходной строки
        delete [] _row;
        // Выделяем память под строку нового размера
        _row = new double [_size];
    }

    // Заполняем строку желаемыми значениями
    for (int i = 0; i < _size; ++i)
        _row[i] = fill;
}
// Перегруженный оператор взятия значения по индексу
double &Row::operator[](int index)
{
    // Возвращаем ссылку на желаемое значение
    return _row[index];
}

// Перегруженный оператор взятия значения по индексу (константный)
const double &Row::operator[](int index) const
{
    // Возвращаем константную ссылку на желаемое значение
    return _row[index];
}

// Перегруженный оператор вывода из потока
std::istream &operator>>(std::istream &input, Row &c)
{
    // Идём по элементам очередной строки
    for (int i = 0; i < c._size; ++i)
        // Выводим значение из потока в очередной элемент строки
        input >> c._row[i];

    // Возвращаем ссылку на поток
    return input;
}

// Перегруженный оператор ввода в поток
std::ostream &operator<<(std::ostream &output, const Row &c)
{
    // Идём по элементам строки
    for (int i = 0; i < c._size; ++i)
    {
        // Если очередной элемент отрицательный - выводим в поток знак "минус"
        if (c._row[i] < 0.0)
            output << '-';
        // Иначе - выводим пробел
        else
            output << ' ';

        // Выводим модуль элемента в поток
        output << (c._row[i] < 0.0 ? -c._row[i] : c._row[i]) << "\t";
    }

    // Возвращаем ссылку на поток
    return output;
}

// Перегруженный оператор сравнения строк
bool Row::operator==(const Row &c) const
{
    // Если размеры строк не совпадают, то строки заведомо не равны
    if (_size != c._size)
        return false;

    // Если значения соответствующих элементов строк различаются,то строки не равны
    for (int i = 0; i < _size; ++i)
        if (_row[i] != c._row[i])
            return false;

    // Если как размеры, так и все соответствующие элементы строк совпадают,строки равны
    return true;
}

// Перегруженный оператор неравенства строк
bool Row::operator!=(const Row &c) const
{
    // Используется уже реализованный оператор сравнения строк
    return !(*this == c);
}

// Перегруженный оператор присваивания одной строки другой
const Row &Row::operator=(const Row &c)
{
    // Проверка на самоприсваивание
    if (this != &c)
    {
        // Если размеры строк не совпадают
        if (_size != c._size)
        {
            // Очищаем память от старой строки
            delete [] _row;

            // Устанавливаем новый размер
            _size = c._size;

            // Выделяем память под новую строку
            _row = new double [_size];
        }

        // Заполняем новую строку элементами из
        // присваиваемой
        for (int i = 0; i < _size; ++i)
            _row[i] = c._row[i];
    }

    return *this;
}
