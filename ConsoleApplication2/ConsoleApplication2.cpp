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

    // Перегрузка оператора -=
    Matrix& operator-=(const Matrix& other) {
        if (m != other.m || n != other.n) {
            std::cerr << "Размеры матрицы не совпадают";
            return *this;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    // Перегрузка оператора -
    Matrix operator-(const Matrix& other) const {
        Matrix result(m, n);
        if (m != other.m || n != other.n) {
            std::cerr << "Размеры матрицы не совпадают";
            return result;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора *
    Matrix operator*(const Matrix& other) const {
        Matrix result(m, other.n);
        if (n != other.m) {
            std::cerr << "Размеры матрицы не совпадают для умножения";
            return result;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Перегрузка оператора !=
    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

    // Перегрузка оператора ==
    bool operator==(const Matrix& other) const {
        if (m != other.m || n != other.n) {
            return false;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); 
    Matrix mat1(2, 3);
    Matrix mat2(2, 3);

    mat1.fillRandom();
    mat2.fillRandom();

    std::cout << "Матрица 1:" << std::endl;
    std::cout << mat1 << std::endl;

    std::cout << "Матрица 2:" << std::endl;
    std::cout << mat2 << std::endl;

    Matrix mat3 = mat1 + mat2;
    std::cout << "Матрица 1 + Матрица 2:" << std::endl;
    std::cout << mat3 << std::endl;

    if (mat1 != mat2) {
        std::cout << "Матрицы разных размеров" << std::endl;
    }
    else {
        std::cout << "Матрицы одного размера" << std::endl;
    }

    return 0;
}
