#ifndef ROW_H
#define ROW_H


class Row
{
    public:
        //конструктор
        Row();
        //конструктор, позволяющий ввести определенное значение в строке
        Row(int, double = 0.0);
        //конструктор копирования
        Row(const Row &);
        //деструктор
        ~Row();
        //функция, изменяющая строку
        //первый аргумент-длина строки
        //второй-заполнитель строки
        void resize(int = 1, double = 0.0);
        //перегрузка оператора доступа к элементу по индексу
        double&operator[](int);
        //то же самое, только константное
        const double &operator[](int) const;
        //перегрузка вывода
        friend std::istream &operator>>(std::istream &, Row &);
        //перегрузка ввода
        friend std::ostream &operator<<(std::ostream &, const Row &);
        //перегрузка оператора равенства строк
        bool operator==(const Row &) const;
        //перегрузка оператора неравенства строк
        bool operator!=(const Row &) const;
        //перегрузка оператора присваивания
        const Row &operator=(const Row &);
    private:
        //указатель на элемент строки
        double *_row;
        //размер строки
        int _size;
};

#endif // ROW_H
