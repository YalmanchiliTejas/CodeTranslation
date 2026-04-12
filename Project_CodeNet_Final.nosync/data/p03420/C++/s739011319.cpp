//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n,k;cin>>n>>k;
  ll ans=0;
  if(k==0){
    cout<<n*n<<endl;
    return 0;
  }
  for(ll b=k+1;b<=n;b++){
    ans+=n/b*(b-k);
    ll d=n%b-(k-1);
    if(d>0)ans+=d;
    //cout<<ans<<" "<<d<<endl;
  }
  cout<<ans<<endl;
}