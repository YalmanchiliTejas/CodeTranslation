#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define PI acos(-1)
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<typename T> using v2 = vector<vector<T>>;
template<typename T> using v3 = vector<vector<vector<T>>>;
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int MOD = 1e9 + 7;
const int INF = 1e9 + 200;
const ll INFLL = 2e18 + 200;

// Last updated 2020-04-30
// Note: Inputs must be within the 32bit integer range (within the mod range).
template<int64_t mod>
struct ModInt {
    int64_t value;

    ModInt() : value(0) {}
    ModInt(int64_t x) : value(x >= 0 ? x % mod : (mod - ((-x) % mod) % mod)) {}

    ModInt &operator+=(const ModInt &input) {
        value += input.value;
        if (value >= mod) value -= mod;
        return *this;
    }    

    ModInt &operator-=(const ModInt &input) {
        value += (mod - input.value);
        if (value >= mod) value -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &input) {
        value = value * input.value % mod;
        return *this;
    }

    ModInt &operator/=(const ModInt &input) {
        *this *= input.inverse();
        return *this;
    }

    ModInt inverse() const {
        int64_t base = value, p = mod;
        pair<int64_t, int64_t> save = {1, 0};
        while (p) {
            int64_t temp = base / p;
            swap(base -= temp * p, p);
            swap(save.first -= temp * save.second, save.second);
        }
        return ModInt(save.first);
    }

    ModInt operator-() const { return ModInt(-value); }

    ModInt operator-(const ModInt &input) const { return ModInt(*this) -= input; }

    ModInt operator+(const ModInt &input) const { return ModInt(*this) += input; }

    ModInt operator*(const ModInt &input) const { return ModInt(*this) *= input; }

    ModInt operator/(const ModInt &input) const { return ModInt(*this) /= input; }

    bool operator==(const ModInt &comparsion) const { return value == comparsion.value; }

    bool operator!=(const ModInt &comparsion) const { return value != comparsion.value; }

    friend istream &operator>>(istream &stream, ModInt &input) {
        int64_t temp;
        stream >> temp;
        input = ModInt<mod>(temp);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const ModInt &input) {
        return stream << input.value;
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), x(value);
        while (n > 0) {
            if (n and 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }

    static const int64_t get_mod() { return mod; }
};

using modint = ModInt<MOD>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    modint tmp = 0;
    for (int i = 0; i < N; i++) tmp += A[i];
    modint ans = 0;
    for (int i = 0; i < N - 1; i++) {
        tmp -= A[i];
        ans += tmp * A[i];
    }
    cout << ans << endl;
}