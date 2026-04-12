
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

ll vs[100000+10];
int n;

int visited[100000+10];

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%lld", &vs[i]);
  }

  ll res = 0;
  for(int ab = 1; ab < n-1; ++ab) {
    ll leftSum = 0;
    ll rightSum = 0;
    for(int i = 1; ab*i < n && n-1-ab*i >= 0; ++i) {
      ll a = n-1 - ab*i;
      ll b = a - ab;
      if(a <= 0 || b <= 0) break;
      if(visited[ab*i] == ab) break;
      visited[ab*i] = ab;
      if(visited[n-1-ab*i] == ab) break;
      visited[n-1-ab*i] = ab;
      leftSum += vs[ab*i];
      rightSum += vs[n-1-ab*i];
      res = max(res, leftSum + rightSum);
    }
  }
  cout << res << endl;
  return 0;
}
