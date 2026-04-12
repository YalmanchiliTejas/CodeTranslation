#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
LL p = 1000000007ll;

int main(void)
{
  LL n;
  cin >> n;
  vector<LL> s(n);
  for(auto &x:s) cin >> x;
  LL answer = 0;
  FOR(a,1,n) {
    LL tmp = 0;
    for(LL pos = 0; pos < n-a; pos += a) {
      if(pos == n-pos-1) break;
      if(pos - a == n-pos-1) break;
      tmp += s[pos];
      tmp += s[n-pos-1];
      answer = max(answer, tmp);
    }
  }
  cout << answer << endl;
  return 0;
}
