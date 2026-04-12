#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
using namespace std;

void solve()
{
  int n;
  cin >> n;
  cout << n*800 - n/15*200 << endl;
}

int main(){cin.tie(0);ios_base::sync_with_stdio(false);solve();return 0;}
