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
// #include<deque>
// #include<multiset>
// #include<bitset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  char b;
  cin >> b;
  for(int i = 1; i < n; i++) {
    char c;
    cin >> c;
    if(b == 'T' && c == 'F') b = 'F';
    else b = 'T';
  }
  cout << b << endl;
  return 0;
}

