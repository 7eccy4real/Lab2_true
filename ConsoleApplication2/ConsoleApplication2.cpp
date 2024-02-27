#include <iostream>
#include <vector>
class Matrix{
private:
    unsigned int m;
    unsigned int n;
    std::vector<std::vector<int>> data;
public:
    //Конструктор
    Matrix(unsigned int m, unsigned int n) :data(m, std::vector<int>(n, 0)), m(m), n(n) {}
    //Деструктор
    ~Matrix() {}
    //Функиция случайного заполнения от 0 до 9
    void fillRandom() {
        srand(time(0));
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }
    //Перегрузка оператора [] доступа к индексу
    std::vector<int>& operator[](unsigned int index) {
        return data[index];

    }
    //Перегрузка оператора вывода в поток<<
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (unsigned int i = 0; i < matrix.m; ++i) {
            for (unsigned int j = 0; j < matrix.n; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
    //Перегрузка оператора +=
    Matrix& operator+=(const Matrix& other) {
        if (m != other.m || n != other.n) {
            std::cerr << "Размеры матрицы не совпадают";
            return *this;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }
    //Перегрузка оператора +
    Matrix operator+(const Matrix& other) const {
        Matrix result(m, n);
        if (m != other.m || n != other.n) {
            std::cerr << "Размеры матрицы не совпадают";
            return result;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};
int main()
{
    Matrix a(3, 3);
    Matrix b(3, 5);
    a.fillRandom();
    b.fillRandom();
    std::cout << "Matrix 1:" << std::endl;
    std::cout << a << std::endl;

    std::cout << "Matrix 2:" << std::endl;
    std::cout << b << std::endl;

    return 0;
}
