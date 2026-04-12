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

#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/
 
const int mx=200010;
const ll mod=1e9+7;

vector<ll> p(60,0);
vector<ll> h(60,0);

ll rec(ll n, ll x){
  if(n==0) return 1;
  if(x<=1){ return 0; }
  if(1<x && x<=1+h[n-1]){ return rec(n-1,x-1); }
  if(x==1+h[n-1]+1){ return p[n-1]+1; }
  if(1+h[n-1]+1<x && x<=1+h[n-1]+1+h[n-1]){ return p[n-1]+1+rec(n-1,x-2-h[n-1]); }
  return 1+p[n-1]*2;
}

int main() {
  ll n,x;
  cin >> n >> x;
  p[0] = h[0] = 1;
  rep(i,n){
    p[i+1] = p[i]*2+1;
    h[i+1] = h[i]*2+3;
  }
  ll ans = rec(n,x);
  cout << ans << endl;
  return 0;
}