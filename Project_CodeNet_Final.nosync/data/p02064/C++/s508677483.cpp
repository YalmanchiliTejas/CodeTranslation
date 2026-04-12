#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 310

int memo[SIZE][SIZE];

int query(int a, int b) {
  if (a == b) return 0;
  if (memo[a][b]) return memo[a][b];

  int d;
  cout << "? " << a << " " << b << endl;
  cout.flush();

  cin >> d;
  return memo[a][b] = memo[b][a] = d;
}

int main(){
  int N, s, t;
  int ds[SIZE], dt[SIZE];

  cin >> N >> s >> t;

  int D = query(s, t);

  for (int i=1; i<=N; i++) {
    ds[i] = query(s, i);
    dt[i] = query(t, i);
  }

  vector<pair<int,int>> vec;

  for (int i=1; i<=N; i++) {
    if (ds[i] + dt[i] == D) {
      vec.push_back({ds[i], i});
    }
  }

  sort(vec.begin(), vec.end());

  vector<int> ans = {};
  int now = s;

  for (auto p : vec) {
    int to = p.second;

    if (query(now, to) == ds[to] - ds[now]) {
      now = to;
      ans.push_back(now);
    }
  }

  cout << "!";

  for (auto p : ans) {
    cout << " " << p;
  }
  cout << endl;

  return 0;
}

