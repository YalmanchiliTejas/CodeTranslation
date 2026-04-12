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
#include <atcoder/segtree>

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
void vdeb(std::vector<T> &da) {
    for (int i = 0;i < da.size();i++) {
        if (i == da.size() - 1) std::cout << da[i];
        else std::cout << da[i] << ' ';
    }
    std::cout << '\n';
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
    for (int i = 0;i < da.size();i++) {
        std::cout << i << ' ';
        vdeb(da[i]);
    }
    std::cout << '\n';
}

using namespace std;
namespace ac = atcoder;

int vv = 0;

int op (int a, int b){return max(a, b);};
int e() {return -1;};
bool f(int x) {return x < vv;}

int main() {
    int n, q; cin >> n >> q;
    vector<int> da(n);
    rip(i,n,0) cin >> da[i];
    ac::segtree<int, op, e> st(da);
    vector<int> ans(0);
    rip(i,q,0) {
        int t,x,v; cin >>t >> x >> v;
        if(t == 1) {
            --x;
            st.set(x, v);
        }
        else if (t == 2) {
            --x;
            ans.push_back(st.prod(x, v));
        }
        else {
            --x;
            vv = v;
            ans.push_back(st.max_right<f>(x)+1);
        }
    }
    for(auto i:ans) printf("%d\n", i);
}