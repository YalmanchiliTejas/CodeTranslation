#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
using namespace std;

void solve()
{
  int r,g,b;
  cin >> r >> g >> b;

  if((r*100 + g*10 + b) % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(){cin.tie(0);ios_base::sync_with_stdio(false);solve();return 0;}
