#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> sumdp(n+1), pdp(n+1);
  sumdp[0]=1;
  pdp[0]=1;
  for(int i=1; i<=n; i++){
    sumdp[i] = sumdp[i-1]*2+3;
    pdp[i] = pdp[i-1]*2+1;
  }
  ll ans=0;
  while(x && n>=2){
    if(x==sumdp[n]){
      x=0;
      ans+=pdp[n];
      n=0;
    }
    else if(x>sumdp[n]/2){
      ans += pdp[n]/2+1;
      x -= sumdp[n]/2+1;
      n--;
    }else{
      x--;
      n--;
    }
  }
  if(x && n==1){
    x--;
    ans+=min(x,3LL);
    n--;
  }
  cout << ans << endl;
  return 0;
}