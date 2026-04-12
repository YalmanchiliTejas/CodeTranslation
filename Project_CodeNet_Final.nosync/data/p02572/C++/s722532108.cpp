
using namespace std;

//#define fileio

#ifndef fileio
#include <iostream>
#endif
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>

typedef long long ll;

#ifdef fileio
ifstream cin;
ofstream cout;
#endif


template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt& operator+=(const ModInt& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator-=(const ModInt& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator*=(const ModInt& p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt& operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }

    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const ModInt& p) {
        return os << p.x;
    }

    friend istream& operator>>(istream& is, ModInt& a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using mint = ModInt< 1000000007 >;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef fileio
    cin.open("Text.txt");
    cout.open("Output.txt");
#endif
    int n;
    cin >> n;
    mint sum = 0;
    mint sumsq = 0;
    for (int i = 0; i < n; i++) {
        mint x;
        cin >> x;
        sum += x;
        sumsq += (x * x);
    }
    cout << (sum * sum - sumsq) / 2 << endl;
    

}
