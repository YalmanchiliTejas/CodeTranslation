#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

ll n,x;
vl a(51,1),p(51,1);

ll f(ll n,ll x){
  if(n==0&&x==0){
    return 1;
  }
  else{
    if(x==0){
      return 0;
    }
    else if(0<x&&x<=a[n-1]){
      return f(n-1,x-1);
    }
    else if(x==a[n-1]+1){
      return p[n-1]+1;
    }
    else if(a[n-1]+1<x&&x<=2*a[n-1]+1){
      return p[n-1]+f(n-1,x-2-a[n-1])+1;
    }
    else
      return p[n];
  }
}

int main() {
  cin >> n >> x;
  FOR(i,1,n+1){
    a[i]=2*a[i-1]+3;
    p[i]=2*p[i-1]+1;
  }
  cout << f(n,x-1) << endl;
}