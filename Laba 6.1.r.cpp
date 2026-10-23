#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i);
void Print(int* b, const int size, int i);
bool Criterion(const int x);
int Count(int* b, const int size, int i);
int Sum(int* b, const int size, int i);
void Zero(int* b, const int size, int i);

int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел

    const int n = 23;
    int b[n];

    int Low = -25;
    int High = 80;

    Create(b, n, Low, High, 0);
    Print(b, n, 0);

    cout << "Count = " << Count(b, n, 0) << endl;
    cout << "Sum   = " << Sum(b, n, 0) << endl;

    Zero(b, n, 0);
    Print(b, n, 0);

    return 0;
}

// формування масиву випадковими числами з [Low; High]
void Create(int* b, const int size, const int Low, const int High, int i)
{
    b[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(b, size, Low, High, i + 1);
}

// виведення масиву в рядок
void Print(int* b, const int size, int i)
{
    cout << setw(4) << b[i];
    if (i < size - 1)
        Print(b, size, i + 1);
    else
        cout << endl;
}

// критерій: елемент додатний і непарний
bool Criterion(const int x)
{
    return x > 0 && x % 2 != 0;
}

// кількість елементів, що задовольняють критерію
int Count(int* b, const int size, int i)
{
    if (i < size)
    {
        if (Criterion(b[i]))
            return 1 + Count(b, size, i + 1);
        else
            return Count(b, size, i + 1);
    }
    else
        return 0;
}

// сума елементів, що задовольняють критерію
int Sum(int* b, const int size, int i)
{
    if (i < size)
    {
        if (Criterion(b[i]))
            return b[i] + Sum(b, size, i + 1);
        else
            return Sum(b, size, i + 1);
    }
    else
        return 0;
}

// заміна нулями елементів, що задовольняють критерію
void Zero(int* b, const int size, int i)
{
    if (Criterion(b[i]))
        b[i] = 0;
    if (i < size - 1)
        Zero(b, size, i + 1);
}