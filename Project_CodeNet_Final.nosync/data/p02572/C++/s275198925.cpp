#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
#define endl "\n"
//#define int long long
#define ALL(x) begin(x),end(x)
#define resort(v) sort((v).rbegin(), (v).rend())
#define _CRT_SECURE_NO_WARNINGS
#define rep(i, n) for (int i = 0; i < n; i++)
const int MOD = 1e9 + 7;
const int INF = 1e18 + 9;
constexpr long double pi = 3.141592653589793238462643383279;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int fact(int i) {
    if (i == 0) return 1;
    return ((fact(i - 1)) * i) % MOD;
}
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int keta(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
int ketasum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int modpow(int a, int n, int mod) {
    int hi = 1;
    while (n > 0) {
        if (n & 1) hi = hi * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return hi;
}
char toSmall(char c) { // 大文字を小文字へ
    return (c + 0x20);
}
char toLarge(char c) { // 小文字を大文字へ
    return (c - 0x20);
}
float myPower(int a, int n) { // aのn乗の計算
    float x = 1;
    while (n > 0) { // 全てのbitが捨てられるまで
        if (n & 1) { // 一番右のbitが１のとき
            x *= a;
        }
        a *= a;
        n >>= 1; // bit全体を右に1つシフトして一番右を捨てる
    }
    return x;
}
bool is_prime(const unsigned n) {
    switch (n) {
    case 0: // fall-through
    case 1: return false;
    case 2: // fall-through
    case 3: return true;
    } // n > 3 が保証された
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (unsigned i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false; // (6の倍数)-1
        if (n % (i + 2) == 0) return false; // (6の倍数)+1
    }
    return true;
}
ll ans;
/*signed*/int main(void) {
    ll n;
    cin >> n;
    vector<ll> vec(n);
    vector<ll> ruiseki(n);
    rep(i, n) {
        cin >> vec[i];
        if (i == 0) ruiseki[i] = vec[i];
        else ruiseki[i] = ruiseki[i - 1] + vec[i];
        if (i != 0) {
            ans += vec[i] * (ruiseki[i - 1]%MOD);
        }
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}