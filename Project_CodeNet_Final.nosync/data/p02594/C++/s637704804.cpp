
#pragma GCC optimize("O3") //コンパイラ最適化用

#define _GLIBCXX_DEBUG //配列に[]でアクセス時のエラー表示
#include <algorithm>   //sort,二分探索,など
#include <bitset>      //固定長bit集合
#include <cassert>     //assert(p)で，not pのときにエラー
#include <cctype>
#include <chrono>  //実行時間計測
#include <cmath>   //pow,logなど
#include <complex> //複素数
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional> //sortのgreater
#include <iomanip>    //setprecision(浮動小数点の出力の誤差)
#include <ios>        // std::left, std::right
#include <iostream>   //入出力
#include <iterator>   //集合演算(積集合,和集合,差集合など)
#include <map>
#include <numeric> //iota(整数列の生成),gcdとlcm,accumulate
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility> //pair
#include <vector>  //可変長配列
using namespace std;
typedef long long LL;
typedef long double LD;

#define ALL(x) x.begin(), x.end()
#define SIZE(x) LL(x.size()) // sizeをsize_tからLLに直しておく
const long long INF = 1e12;
const int MOD = 1e9 + 7;
#define MAXR 100000 // 10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define UMAP unordered_map
#define USET unordered_set
#define FF first
#define SS second
#define int long long
#define LD long double
#define PII pair<int, int>
#define PB push_back
#define MP make_pair
#define SZ(x) (int)((x).size())
#define VI vector<int>
#define VVI vector<vector<int>>
#define VLL vector<LL>
#define VVLL vector<vector<LL>>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(b)-1; i >= (int)a; i--)

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1},
          Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

// https://qiita.com/Lily0727K/items/06cb1d6da8a436369eed#c%E3%81%A7%E3%81%AE%E5%AE%9F%E8%A3%85
void print() { cout << "\n"; }

template <class Head, class... Tail> void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail) != 0)
        cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T> void print(vector<T> &vec) {
    for (auto &a : vec) {
        cout << a;
        if (&a != &vec.back())
            cout << " ";
    }
    cout << "\n";
}

template <class T> void print(set<T> &set) {
    for (auto &a : set) {
        cout << a << " ";
    }
    cout << "\n";
}

template <class T> void print(vector<vector<T>> &df) {
    for (auto &vec : df) {
        print(vec);
    }
}
long long power(long long x, long long n) {
    // O(logn)
    // https://algo-logic.info/calc-pow/#toc_id_1_2
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret *= x; // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1; // n を1bit 左にずらす
    }
    return ret;
}
long long comb(int n, int k) {
    vector<vector<long long>> v(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i < SZ(v); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int k = 1; k < SZ(v); k++) {
        for (int j = 1; j < k; j++) {
            v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
        }
    }
    return v[n][k];
}
void add(long long &a, long long b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

__attribute__((constructor)) void faster_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int x;
signed main() {
    cin >> x;
    (x >= 30) ? print("Yes") : print("No");
    return 0;
}
