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

  ll n,m;cin>>n>>m;
  // ll a[m],b[m];
  vector<vector<ll>>v(n);
  rep(i,0,m){
    ll a,b;cin>>a>>b;
    --a,--b;
    v[a].push_back(b);
    v[b].push_back(a);
    // cin>>a[i]>>b[i];
  }

  ll per[n];rep(i,0,n)per[i]=i;

  ll ans=0;
  do{
    if(per[0]!=0)continue;
    bool e=true;
    rep(i,0,n-1){
      if(find(v[per[i]].begin(),v[per[i]].end(),per[i+1])==v[per[i]].end())e=false;

    }
    if(e)ans++;

  }while(next_permutation(per,per+n));

  out(ans);

  return 0;
}
