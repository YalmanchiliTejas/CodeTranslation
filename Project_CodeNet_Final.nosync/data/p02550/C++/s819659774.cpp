// #include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <climits>
#include <string>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <stack>
#include <random>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
void vdeb(std::vector<T> &bb) {
    for (int i = 0;i < bb.size();i++) {
        if (i == bb.size() - 1) std::cout << bb[i];
        else std::cout << bb[i] << ' ';
    }
    std::cout << '\n';
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &bb) {
    for (int i = 0;i < bb.size();i++) {
        std::cout << i << ' ';
        vdeb(bb[i]);
    }
    std::cout << '\n';
}

using namespace std;

int main() {
    ll n, x, m; cin >> n >> x >> m;
    vector<ll> da(m);
    rip(i,m,0) da[i] = i*i%m;
    vector<bool> used(m, false);
    ll now = x, cnt = 0;
    ll ans = 0;
    while(!used[now]&&cnt<n) {
        ans += now;
        cnt++;
        used[now] = true;
        now = now*now%m;
        // cout << now << endl;
    }
    if(cnt == n) {
        cout << ans << endl;
        return 0;
    }
    ll subsum = 0, subnow = now, subcnt = 0;
    n -= cnt;
    used = vector<bool>(m, false);
    while(!used[subnow]) {
        subsum += subnow;
        subcnt += 1;
        used[subnow] = true;
        subnow = subnow*subnow%m;
        // cout << subnow << endl;
    }
    // cout << ans MM subcnt MM subsum << endl;
    ans += n/subcnt*subsum;
    n %= subcnt;
    while(n) {
        ans += now;
        now = now*now%m;
        --n;
    }
    cout << ans << endl;
}