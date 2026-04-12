#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(void)
{
  LL n;
  cin >> n;
  LL max = 0,answer = 0;
  REP(i,n) {
    LL h;
    cin >> h;
    if(h<max) continue;
    ++answer;
    max=h;
  }
  cout << answer << endl;
  return 0;
}
