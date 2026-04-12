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
using ll=long long;
using ld=long double;
//#define int long long
#define _CRT_SECURE_NO_WARNINGS
#define rep(i, n) for (int i = 0; i < n; i++)
#define _GLIBCXX_DEBUG
#define ALL(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;
const int INF = 1e18 + 9;
constexpr long double pi = 3.141592653589793238462643383279;
int fact(int i) {
    if (i == 0) return 1;
    return (fact(i - 1)) * i;
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

int main(void) {
    int h;
    cin >> h;
    int w;
    cin >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        if (row[i]) {
            for (int j = 0; j < w; j++) {
                if (col[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}