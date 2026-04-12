#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll mod_div(ll a,ll b){
  ll tmp=MOD-2,c=b,ret=1;
  while(tmp>0){
    if(tmp&1){
      ret*=c;ret%=MOD;
    }
    c*=c;c%=MOD;tmp>>=1;
  }
  return a*ret%MOD;
}
 
#define MAX_K 2000100
vector<ll> kaijo(MAX_K);
ll combination(ll n, ll r){
  if(n<r||n<0||r<0)
    return 0;
  if(kaijo[0]!=1){
    kaijo[0]=1;
    for(ll i=1;i<MAX_K;i++)kaijo[i]=(kaijo[i-1]*i)%MOD;
  }
  ll ret=kaijo[n];
  long long tmp = (kaijo[r] * kaijo[n-r]) % MOD;
  return mod_div(ret,tmp);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m,k;cin>>n>>m>>k;
  ll kake = combination(n*m-2,k-2);
  ll ans = 0;
  for(ll i=1;i<n;i++){
    ans += kake*(((((m*m%MOD)*i)%MOD)*(n-i))%MOD)%MOD;
    ans %= MOD;
  }
  for(ll i=1;i<m;i++){
    ans += kake*(((((n*n%MOD)*i)%MOD)*(m-i))%MOD)%MOD;
    ans %= MOD;
  }
  cout<<ans<<endl;
  return 0;
}
