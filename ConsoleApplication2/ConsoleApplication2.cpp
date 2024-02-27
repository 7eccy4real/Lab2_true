#include <iostream>
#include <vector>
using namespace std;
class Matrix{
private:
    unsigned int m;
    unsigned int n;
    vector<vector<int>> data;
public:
    Matrix(unsigned int m, unsigned int n) :data(m, vector<int>(n, 0)), m(m), n(n) {}
    ~Matrix() {}
    void fillRandom() {
        srand(time(0));
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    }
};
int main()
{
    Matrix a(3, 3);

    return 0;
}
