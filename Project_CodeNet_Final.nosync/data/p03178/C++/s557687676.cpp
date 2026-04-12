#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<int mod>
struct Ring_mod {
    int val;
    Ring_mod(): val(0) {}
    Ring_mod(long long x)
    {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        if (x >= mod) x %= mod;
        val = x;
    }
    explicit operator int() { return val; }
    Ring_mod operator+(const Ring_mod& b) { return Ring_mod(val + b.val); }
    Ring_mod operator-(const Ring_mod& b) { return Ring_mod(val - b.val); }
    void operator+=(const Ring_mod& b) { val = Ring_mod(val + b.val).val; }
    void operator-=(const Ring_mod& b) { val = Ring_mod(val - b.val).val; }
    Ring_mod operator*(const Ring_mod& b) { return Ring_mod((long long) val * b.val); }
};

const int MOD = 1e9 + 7;
typedef Ring_mod<MOD> int_mod;

template<typename T>
struct Matrix {
    Matrix(int r, int c) : _r(r), _c(c), a(r * c) {}
    T* operator[](int row) { return row * _c + a.data(); }
    int _r, _c;
    vector<T> a;
};

int main()
{
    string a;
    int d;
    cin >> a >> d;
    int n = a.size();

    Matrix<int_mod> f(n + 1, d);
    f[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int u = 0; u < d; ++u)
            for (int k = 0; k < 10; ++k) {
                int v = (u + k) % d;
                f[i + 1][v] += f[i][u];
            }

    int p = 0;
    int_mod res = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i] - '0';
        for (int j = 0; j < x; ++j) {
            int v = (p + j) % d;
            if (v == 0) v = d;
            res += f[n - i - 1][d - v];
        }
        p += x;
    }
    if (p % d == 0)
        res += 1;
    res -= 1;   // don't count zero
    cout << (int) res;
    return 0;
}
