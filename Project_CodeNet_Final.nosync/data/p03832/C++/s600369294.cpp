#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

ll memo[1000+1][1000+1];
ll n,a,b,c,d;


ll modpow(ll b, ll e, ll p) {
  if(e==0) return 1;
  if(e%2==0) {
    ll t = modpow(b,e/2,p);
    return (t*t)%p;
  }
  return (b*modpow(b,e-1,p))%p;
}

ll modinv(ll n, ll p) {
  return modpow(n,p-2,p);
}

const ll p = 1e9+7;
const int MX = 1000;
ll modFact[MX+1];
ll modFactInv[MX+1];
void precalc() {
  modFact[0]=1;
  modFactInv[0]=1;
  repeat(i,1,MX+1) {
    modFact[i]=(modFact[i-1]*i)%p;
    modFactInv[i]=modinv(modFact[i],p);
  }
}

ll fastModComb(ll n, ll k, ll p) {
  // call precalc() first.
  ll ret=modFact[n];
  ret=ret*modFactInv[n-k];
  ret%=p;
  ret=ret*modFactInv[k];
  ret%=p;
  return ret;
}

ll f(ll j, ll i, ll k) {
  ll ret=modFact[j];
  ret*=modFactInv[j-i*k];
  ret%=p;
  ret*=modpow(modFactInv[i],k,p);
  ret%=p;
  ret*=modFactInv[k];
  ret%=p;
  return ret;
}

ll dp(ll i, ll j) {
  if(i<a&&j!=0) {
    return 0;
  }
  if(j==0) {
    return 1;
  }
  if(memo[i][j]!=-1)
    return memo[i][j];
  ll ret=0;
  ret+=dp(i-1,j);
  repeat(k,c,d+1) {
    if(j-k*i<0)
      break;
    ret+=f(j,i,k)*dp(i-1,j-k*i);
    ret%=p;
  }
  return memo[i][j]=ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  memset(memo,-1,sizeof(memo));
  cin>>n>>a>>b>>c>>d;
  precalc();
  cout << dp(b,n) << endl;
  //cout << f(4,2,1) << endl;
  return 0;
}
