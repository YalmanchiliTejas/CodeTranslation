#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull p2[61];

ull f(int x) {
  return p2[x+2]-3;
}

ull p(int x) {
  return p2[x+1]-1;
}

ull solve (int level, ull x) {
  if (level == 0) 
    return (x == 1 or x == 2 ? 1 : 0);
  if (x < f(level-1)+2) {
    return solve(level-1,x-1);
  } else if (x == f(level-1)+2) {
    return p(level-1)+1;
  } else if (x <= f(level)-1) {
    return solve(level-1,x-f(level-1)-2)+p(level-1)+1;
  }
  return p(level);
}

int main () {
  p2[0] = 1;
  for (ull i = 1; i < 61; i++)
    p2[i] = p2[i-1]*2;
  ull n, x; cin >> n >> x;
  cout << solve(n,x) << endl;
  return 0;
}