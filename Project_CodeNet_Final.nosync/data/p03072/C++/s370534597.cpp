#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define REP(i,n) for(int i=0;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define ALL(a) (a).begin(),(a).end()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int ans = 1;
  int maxH;
  cin >> maxH;

  REP(i, n-1) {
    int tmp;
    cin >> tmp;
    if(tmp >= maxH) {
      ans++;
    }
    maxH = max(tmp, maxH);
  }

  cout << ans << endl;
  return 0;
}
