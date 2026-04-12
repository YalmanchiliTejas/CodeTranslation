#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

const int N = 2e5 + 5;

bool arr[N];

int LIS(const vector<int>& v) {
  multiset<int> s; // multiset if there are duplicates
  for (int x : v) {
    auto it = s.upper_bound(x); // lower_bound for strictly increasing
    if (it != s.end()) s.erase(it);
    s.insert(x);
  }
  return s.size();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  vector <int> vec(n);

  for (int& x : vec) {
    cin >> x;
    x *= -1;
  }

  cout << LIS(vec) << endl;


}
