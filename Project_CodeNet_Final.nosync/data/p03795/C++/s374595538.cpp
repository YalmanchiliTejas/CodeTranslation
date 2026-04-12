// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
signed main(){
  ll n,ans=0;
  cin >> n;
  for(int i=1;i<=n;i++){
    ans += 800;
    if(i%15==0) ans -= 200;
  }
  cout << ans << endl;
}
