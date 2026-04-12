#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long int li;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define all(x) (x).begin(),(x).end()
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const ll INF = 1LL<<60;
const lb PI=3.14159265359;

int main(){

  ll a,b,c;cin>>a>>b>>c;
  ll x,y;cin>>x>>y;

  ll mi=INF;
  rep(i,0,max(x,y)+1){
    chmin(mi,i*2*c+max((ll)0,x-i)*a+max((ll)0,y-i)*b);
  }
  out(mi);
  return 0;
}
