#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

vector<ll> a(60);
vector<ll> p(60);

ll hbg(ll i, ll x){
  if(i==0&&x==1){ return 1; }
  if(x==1){ return 0; }
  if(1<x && x<=1+a[i-1]){ return hbg(i-1,x-1);}
  if(x==2+a[i-1]){ return p[i-1]+1;}
  if(2+a[i-1]<x && x<=2+2*a[i-1]){ return p[i-1]+1 + hbg(i-1,x-2-a[i-1]);}
  if(x==3+2*a[i-1]){ return 1+2*p[i-1]; }
}

int main(){
  ll n,k;
  cin >> n >> k;
  a[0]=1; p[0]=1;
  rep(i,n){
    a[i+1]=2*a[i]+3;
    p[i+1]=2*p[i]+1;
  }
  ll ans=hbg(n,k);
  cout << ans << endl;
  return 0;
}
