#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

vector<ll> a(51);
vector<ll> p(51);

ll solve(ll n,ll x){

  if(n==0){
    if(x<=0){
      return 0;
    }else{
      return 1;
    }
  }else if(x <= 1+a[n-1]){
    return solve(n-1, x-1);
  }else{
    return p[n-1] + 1 + solve(n-1, x-2-a[n-1]);
  }
}


int main(){

  ll n, x;
  cin >> n >> x;
  
  a[0] = 1;
  p[0] = 1;

  rep(i,50){
    a[i+1] = a[i]*2 + 3;
    p[i+1] = p[i]*2 + 1;
  }

  cout << solve(n,x) << endl;

  return 0;
} 