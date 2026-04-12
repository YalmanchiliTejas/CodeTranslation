#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int MOD = 1000000007;
ll gcd(ll x, ll y){
  if(y==0)return x;
  else return gcd(y,x%y);
}
int main() {
  ll n,k;
  cin >> n >> k;
  ll sum=0;
  if(k==0){
    sum=n*n;
    cout << sum << endl;
    return 0;
  }
  
  for(ll b=k+1;b<=n;b++){
    ll a=k;
    while(a<=n){
      if(a+b-k-1<=n){
        sum+=b-k;
        a+=b;
      }
      else{
        sum+=n-a+1;
        break;
      }
    }
  }
  
  cout << sum << endl;
  
}