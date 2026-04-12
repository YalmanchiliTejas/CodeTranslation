/*{{{*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
// pll pp; -> (pp.first,pp.second)
// vector<vl> pp(n,vl(2)); sort(pp.begin(),pp.end(),[](vl a,vl b){return a[0]<b[0];});

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define RREP(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define DEBUG(x) cout << #x << ": " << x << endl
#define CHMAX(a,b) a=max((a),(b))
#define CHMIN(a,b) a=min((a),(b))
/*}}}*/
int main() {
  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 0;
  if(a+b>2*c){
    ll m = min(x,y);
    ans += 2*c*m;
    x -= m;
    y -= m;
  }
  if(a>2*c) ans += 2*c*x;
  else ans += a*x;
  if(b>2*c) ans += 2*c*y;
  else ans += b*y;
  cout << ans << endl;
  return 0;
}
