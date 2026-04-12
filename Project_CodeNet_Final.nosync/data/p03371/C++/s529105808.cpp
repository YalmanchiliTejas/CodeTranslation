#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int a,b,c,x,y;
  ll ans=INF;
  cin >> a >> b >> c >> x >> y;
  c*=2;
  rep(i,100001){
    ll tmp=c*i+max(x-i,0)*a+max(y-i,0)*b;
    chmin(ans,tmp);
  }
  cout << ans << endl;

  return 0;
}
