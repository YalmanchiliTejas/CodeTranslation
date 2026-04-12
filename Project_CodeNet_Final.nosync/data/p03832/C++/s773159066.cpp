#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <functional>
#include <set>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<int,int>;
const ll M = 1e9+7, mx = 200000;
void add(ll& x, ll y) {x+=y; x%=M;}; void mul(ll& x, ll y) {x*=y; x%=M;}; void chmax(ll& x, ll y) {if (x<y) x=y;}; void chmin(ll& x, ll y) {if (x>y) x=y;};
ll mod_pow(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x % M; x = x * x % M; a >>= 1;} return an;}
vector<ll> sm(2002), inv(2002);
void sm_build() {
	sm[0]=1;for(ll i=1;i<=2001;i++) sm[i]=sm[i-1]*i%M;
	inv[2001]=mod_pow(sm[2001],M-2);for(ll i=2000;i>=0;i--) inv[i]=inv[i+1]*(i+1)%M;
}

int main() {
  sm_build();
  ll n,a,b,c,d; cin>>n>>a>>b>>c>>d;
  ll dp[n+1]; fill(dp,dp+n+1,0);
  dp[0]=1;
  ll su[n+1];
  for(ll j=a;j<=b;j++) {
    fill(su,su+n+1,0);
    for(ll k=c;k<=d;k++) {
      if (n < j*k) break;
      ll mu = inv[k] * mod_pow(inv[j], k) % M;// j*k個からj個をk個抜く これはk個に区別
      //cout<<j<<" "<<k<<" "<<mu<<endl;
      int p = n-j*k;
      for(int i=p;i>=0;i--) {
        ll lf = n-i;
        ll ad = sm[lf] * inv[lf-j*k] % M;
        ad = ad * mu % M; ad = ad * dp[i] % M;
        int vu = i+j*k;
        add(su[vu],ad);
      }
    }
    for(int i=0;i<=n;i++) {
      add(dp[i],su[i]);
    }
    /*
    for(int i=0;i<=n;i++) {
      cout<<dp[i]<<" ";
    } cout<<endl;*/
  }
  /*
  for(int i=0;i<=n;i++) {
    cout<<dp[i]<<" ";
  } cout<<endl;*/
  cout<<dp[n]<<endl;
}