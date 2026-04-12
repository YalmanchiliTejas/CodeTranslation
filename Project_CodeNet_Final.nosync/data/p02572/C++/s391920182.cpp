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
int INF = 1e9 + 7;
int mod = 998244353;
long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998626034825342117;
struct Edge {
    long long to;
    long long cost;
};//to...辺 cost...重み これをそれぞれ隣接グラフとして格納
void dijkstra(const vector<vector<Edge> > & G, long long s, vector<long long> & dis) {//Gは隣接グラフ,sは始点,距離の結果をdisに格納
    long long N = G.size();
    dis.resize(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {//
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto& e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
    return;
}
long double kodohou(long double N) {
    return N * 180.0 / PI;
}
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
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
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
signed gcd(long long x, long long y) {
    if (y == 0)return x;
    return gcd(y, x % y);
}
signed lcm(long long x, long long y) {
    return x / gcd(x, y) * y;
}
long long RepeatSquaring(long long N, long long P, long long M) {
    if (P == 0) return 1;
    if (P % 2 == 0) {
        long long t = RepeatSquaring(N, P / 2, M);
        return t * t % M;
    }
    return N * RepeatSquaring(N, P - 1, M);
}
long long Fibonacci(long long A) {
    if (A == 1)return 1;
    vector<long long>B(A + 1); B[0] = 1; B[1] = 1;
    for (int i = 2; i <= A; i++) { B[i] = B[i - 1] + B[i - 2]; B[i] %= mod; }
    return B[A];
}
int mod_pow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return res;
}
int fac[100005], finv[100005], inv[100005];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 100005; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
int COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
signed main() {
    int N; cin >> N;
    vector<long long>A(N);
    long long count = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        count += A[i];
        count %= INF;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (count - A[i] < 0)count += INF;
        ans += (count - A[i]) * A[i];
        ans %= INF;
        count -= A[i];
    }
    cout << ans << endl;
}