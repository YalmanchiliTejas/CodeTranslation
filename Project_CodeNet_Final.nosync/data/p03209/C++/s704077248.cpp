#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

vector<ll> ban(51);
vector<ll> paty(51);

long long dfs(ll n, ll x, ll sum){
  if(n == 0){
   	return sum+1; 
  }
  if(x == 1){
    return sum;
  }else if(1<x && x<ban[n]/2+1){
    return dfs(n-1, x-1, sum);
  }else if(x == ban[n]/2+1){
    return sum+paty[n-1]+1;
  }else if(ban[n]/2+1 < x && x < ban[n]){
    return dfs(n-1, x-(ban[n-1]+2), sum+paty[n-1]+1);
  }else if(x == ban[n]){
    return sum+paty[n];
  }
}

int main(){
  ll n, x;
  cin >> n >> x;
  ban[0] = 1;
  paty[0] = 1;
  for(ll i=1; i<=50; i++){
    ban[i] = ban[i-1]*2+3;
    paty[i] = paty[i-1]*2+1;
  }
  ll ans = dfs(n, x, 0);
  cout << ans << endl;
  return 0;
}
    
    