// Lab10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

class Triangle {
public:
    virtual double calculateArea() const = 0;

    // Функція для обчислення довільної медіани трикутника
    virtual double calculateMedian(double side1, double side2, double side3) const {
        // Для простоти використовуємо формулу медіани та середньої лінії у рівнобедреному трикутнику
        return 0.5 * sqrt(2 * pow(side1, 2) + 2 * pow(side2, 2) - pow(side3, 2));
    }

    // Функція для знаходження паралельної середньої лінії за довільною стороною
    virtual double calculateParallelMedian(double side) const {
        return 0.5 * side;
    }
};

class TriangleByVertices : public Triangle {
private:
    double x1, y1, x2, y2, x3, y3;

public:
    TriangleByVertices(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    double calculateArea() const override {
        return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }
};

class TriangleBySides : public Triangle {
private:
    double side1, side2, side3;

public:
    TriangleBySides(double side1, double side2, double side3)
        : side1(side1), side2(side2), side3(side3) {}

    double calculateArea() const override {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Функція для обчислення радіуса вписаного кола
    double calculateInradius() const {
        return calculateArea() / (0.5 * (side1 + side2 + side3));
    }

    // Функція для обчислення радіуса описаного кола
    double calculateCircumradius() const {
        return (side1 * side2 * side3) / (4 * calculateArea());
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x1, y1, x2, y2, x3, y3;
    cout << "Введіть координати вершин трикутника (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    TriangleByVertices triangleVertices(x1, y1, x2, y2, x3, y3);

    double side1, side2, side3;
    cout << "Введіть довжини сторін трикутника: ";
    cin >> side1 >> side2 >> side3;

    TriangleBySides triangleSides(side1, side2, side3);

    cout << "Площа трикутника за вершинами: " << triangleVertices.calculateArea() << endl;
    cout << "Площа трикутника за сторонами: " << triangleSides.calculateArea() << endl;

    // Обчислюємо та виводимо медіани трикутника
    cout << "Медіана трикутника за сторонами: " << triangleSides.calculateMedian(side1, side2, side3) << endl;

    // Обчислюємо та виводимо середню лінію трикутника за довільною стороною
    cout << "Паралельна середня лінія трикутника за стороною " << side1 << ": "
        << triangleSides.calculateParallelMedian(side1) << endl;

    // Обчислюємо та виводимо радіуси вписаного і описаного кола
    cout << "Радіус вписаного кола: " << triangleSides.calculateInradius() << endl;
    cout << "Радіус описаного кола: " << triangleSides.calculateCircumradius() << endl;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
