//#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>

#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
#include <utility>
#include <array>
#include <complex>
#include <valarray>

#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>

#include<memory>


using namespace std;
#define int long long

typedef long long ll;
typedef unsigned long long ull;
//typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<double,int> pdi;
typedef pair<long double, int> pdbi;
typedef pair<int,pii> pipii;
typedef pair<ll,pll> plpll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vector<int>> mat;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const int INF = 1<<30;
const ll INFLL = 1LL<<62;
const long double EPS = 1e-12;
const ll mod = 1000000000 + 7;
//const ll mod = 998244353;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const long double pi = 3.141592653589793;

#define addm(X, Y) (X) = ((X) + ((Y) % mod) + mod) % mod
#define inside(y, x, h, w) (0 <= (y) && (y) < (h) && 0 <= (x) && (x) < (w)) ? true : false

//debug
#define DEBUG

#define DUMPOUT cout

#ifdef DEBUG
#define dump(...) DUMPOUT<<#__VA_ARGS__<<" :["<<__FUNCTION__<<":"<<__LINE__<<"]"<<endl; DUMPOUT<<"    "; dump_func(__VA_ARGS__)
#else
#define dump(...)
#endif

void dump_func() {DUMPOUT << endl;};

template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) == 0) DUMPOUT << " ";
    else DUMPOUT << ", ";
    dump_func(std::move(tail)...);
}

//ostream
template<typename T> ostream& operator << (ostream& os, vector<T>& vec) {
    os << "["; for (int i = 0; i<vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : ", "); os << "]";
    return os;
}

template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& map_var) {
    os << "[";
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")"; itr++;  if(itr != map_var.end()) os << ", "; itr--;
    }
    os << "]";
    return os;
}

template<typename T> ostream& operator << (ostream& os, set<T>& set_var) {
    os << "[";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr; ++itr; if(itr != set_var.end()) os << ", "; itr--;
    }
    os << "]";
    return os;
}

struct segtree {
    int size;
    vector<long long> node;

    segtree (int n) : size(1) {
        while (size < n) size *= 2;
        node.resize(2 * size - 1, INFLL / 2);
    }

    void update(int k, int a) {
        k += size - 1;
        node[k] = a;
        while (k > 0){
            k = (k - 1) / 2;
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    //[queryL: queryR)
    long long get(int queryL, int queryR, int k = 0, int nodeL = 0, int nodeR = -1) {
        if (nodeR == -1) nodeR = size;
        if (nodeR <= queryL || queryR <= nodeL) return INFLL;//初期値より大きく
        if (queryL <= nodeL && nodeR <= queryR) return node[k];
        else{
            int nodeM = (nodeL + nodeR) / 2;
            long long vl = get(queryL, queryR, 2 * k + 1, nodeL, nodeM);
            long long vr = get(queryL, queryR, 2 * k + 2, nodeM, nodeR);
            return min(vl, vr);
        }
    }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  while (true) {
    string s;
    cin >> s;
    if (s == "#") break;
    vector<vector<char>> g(10);
    int n = s.size();
    int h = 0;
    int w = 0;
    rep(i, n) {
      if (s[i] == '/') {
        w = g[h].size();
        h++;
        continue;
      }
      if (s[i] == 'b') {
        g[h].push_back('b');
      }
      else {
        int num = s[i] - '0';
        rep(_, num) g[h].push_back('.');
      }
    }
    h++;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    g[a][b] = '.';
    g[c][d] = 'b';
    string ans = "";
    rep(i, h) {
      rep(j, w) {
        if (g[i][j] == 'b') {
          ans += 'b';
        }
        else {
          int cnt = 0;
          while (j < w && g[i][j] == '.') {
            j++;
            cnt++;
          }
          j--;
          ans += to_string(cnt);
        }
      }
      if (i != h - 1) {
        ans += '/';
      }
    }
    cout << ans << endl;
  }
}

