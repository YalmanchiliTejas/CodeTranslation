#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main() {
ll A;
  ll B;
   ll C;
  ll X;
   ll Y;
  cin >>A>>B>>C>>X>>Y;
  C=2*C;
  //cout<<C<<endl;
  ll z=max(X,Y);
  ll w=min(X,Y);
  vl c(z+1);
  rep(i,z+1) {
    if(i<w) {
      c.at(i)+=C*i;
      c.at(i)+=A*(X-i)+B*(Y-i);
    }
    
    else if ((i<z)&&(i>=w)) {
      if(X<=i) {
        c.at(i)+=C*i;
        c.at(i)+=(Y-i)*B;
      }
      if(Y<=i) {
c.at(i)+=C*i;
        c.at(i)+=(X-i)*A;
      }
    }
    if(i==z) {
      c.at(i)+=C*i;
    }
  }
  
  sort(all(c));
  cout<<c.at(0)<<endl;
  
}
      
      
