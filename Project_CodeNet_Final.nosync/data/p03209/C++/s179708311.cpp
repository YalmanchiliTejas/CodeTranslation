#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
ll gcd(ll x, ll y){
  if(y==0) return x;
  else return gcd(y, x%y);
}
ll lcm(ll x,ll y){
  ll g=gcd(x,y);
  return x/g*y;
}
ll a[55],b[55];
ll f(int n, ll x){
  if(!x) return 0;
  if(!n) return 1;
  if(x<a[n-1]+2) return f(n-1,x-1);
  return b[n-1]+1+f(n-1,x-2-a[n-1]);
}
          
  
int main() {
  int N; 
  cin >> N;
  ll X;
  cin >> X;
  a[0] = 1, b[0] = 1;
  rep(i,N){
    a[i+1]=a[i]*2+3;
    b[i+1]=b[i]*2+1;
  }
  ll ans=f(N,X);
  cout << ans << endl;
}
  

