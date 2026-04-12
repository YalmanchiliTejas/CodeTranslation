#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef pair<string,string> Pstring;
typedef pair<double,double> Pdouble;

#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define Precision(i) cout << fixed << setprecision(i)

const double PI=3.14159265358979323846;
const int MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {

  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  ll ans = INF;

  ans = min(ans,x*a+y*b);
  ans = min(ans,max(x,y)*2*c);

  if(x>y){
    ans = min(ans,y*2*c+(x-y)*a);
  }else{
    ans = min(ans,x*2*c+(y-x)*b);
  }

  cout << ans << endl;
}