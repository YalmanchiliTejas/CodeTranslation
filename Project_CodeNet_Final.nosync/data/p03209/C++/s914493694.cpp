#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;

vector<ll>a(50),p(50);
ll f(ll x, ll y){
  if(!x){
    if(y>0) return 1;
    else return 0;
  }
  else if(y<=a[x-1]+1) return f(x-1,y-1);
  else if(y==a[x-1]+2) return p[x-1]+1;
  else if(y==2*a[x-1]+3) return 2*p[x-1]+1;
  else return p[x-1]+1+f(x-1,y-2-a[x-1]);
}

void solve(){
  ll n,x; cin >>n >>x;
  a[0]=1; p[0]=1;
  for(int i=1; i<n; i++){
    a[i]=2*a[i-1]+3;
    p[i]=2*p[i-1]+1;
  }
  cout <<f(n,x);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
return 0;}