// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  while(1) {
    int n;
    cin >> n;
    if(!n) break;
    vector<int> v(n);
    for(auto &e: v) cin >> e;
    sort(begin(v), end(v));
    ll sum = 0;
    for(int i = 1; i < n - 1; i++) sum += v[i];
    cout << sum / (n - 2) << "\n";
  }
  return 0;
}

