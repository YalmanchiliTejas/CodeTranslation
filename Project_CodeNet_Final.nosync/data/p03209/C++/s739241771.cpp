//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;
// const int INF = 1000000;


ll pa(ll n){
  if(n > 0) return 2*pa(n-1)+1;
  else return 1;
}

ll search(ll n,ll x,ll sum){
  if(n == 0){
    return 1;
  }
  if(x == sum){
    return 2*pa(n-1) + 1;
  }else if(x > (sum+1)/2){
    return pa(n-1) + 1 + search(n-1,x-(sum+1)/2,(sum-3)/2);
  }else if(x == (sum+1)/2){
    return pa(n-1) + 1;
  }else if(x > 1){
    return search(n-1,x-1,(sum-3)/2);
  }else{
    return 0;
  }
}



int main(){
  ll n,x;
  cin >> n >> x;
  ll w;
  w = 4*pow(2,n) - 3;
  ll ans;
  ans = search(n,x,w);
  printf("%lld\n", ans);

  return 0;
}
