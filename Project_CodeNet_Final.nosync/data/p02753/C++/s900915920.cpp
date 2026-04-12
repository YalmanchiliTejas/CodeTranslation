////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
const int MOD = 1000000007;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T absolute(const T& n);
template <class T>
void input(vector<T>& vec);
template <class T>
void output(const vector<T>& vec);
template <class T>
T sum(const vector<T>& vec);
template <class T>
double average(const vector<T>& vec);
template <class T>
void upsort(vector<T>& vec);
template <class T>
void downsort(vector<T>& vec);
template <class T>
T max(const vector<T>& vec);
template <class T>
T min(const vector<T>& vec);

template <class T>
vector<bool> isPrime(T max);
//isPrime[n] はnが素数のときtrue，合成数のときfalseを返す

void combination_init();
ull combination(int n, int r);
//一度 combination_init() を実行したのち，combination(n,r) で nCr mod MOD を返す
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    string S;
    cin >> S;
    if(S=="AAA"||S=="BBB"){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T absolute(const T& n)
{
    if (n < 0) {
        return (-n);
    }
    return n;
}

template <class T>
void input(vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i) {
        cin >> vec.at(i);
    }
}

template <class T>
void output(const vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

template <class T>
T sum(const vector<T>& vec)
{
    T initial = 0.0;
    T s = accumulate(vec.begin(), vec.end(), initial);
    return s;
}

template <class T>
double average(const vector<T>& vec)
{
    double ave = static_cast<double>(sum(vec)) / static_cast<double>(vec.size());
    return ave;
}

template <class T>
void upsort(vector<T>& vec)
{
    sort(vec.begin(), vec.end());
}

template <class T>
void downsort(vector<T>& vec)
{
    sort(vec.begin(), vec.end(), greater<T>());
}

template <class T>
T max(const vector<T>& vec)
{
    T m = vec.at(0);
    for (size_t i = 0; i < vec.size(); ++i) {
        m = max(m, vec.at(i));
    }
    return m;
}

template <class T>
T min(const vector<T>& vec)
{
    T m = vec.at(0);
    for (size_t i = 0; i < vec.size(); ++i) {
        m = min(m, vec.at(i));
    }
    return m;
}

template <class T>
vector<bool> isPrime(T max)
{
    vector<bool> isPrime(static_cast<size_t>(max + 1), true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (size_t i = 2; static_cast<int>(i * i) <= max; ++i) {
        if (isPrime[i]) {
            for (size_t j = 2; static_cast<int>(i * j) <= max; ++j) {
                isPrime[i * j] = false;
            }
        }
    }
    return isPrime;
}

const ull MAX = 10000000;
ull fac[MAX], finv[MAX], inv[MAX];
void combination_init()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ull i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ull combination(int n, int r)
{
    if (n < r)
        return 0;
    if (n < 0 || r < 0)
        return 0;
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////