#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
 
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;


int main(){
  ll MOD = 1000000007;
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> modest(N);
  rep(i,N){
    cin >> A.at(i);
    if(i>0){
      modest.at(i) = modest.at(i-1) + A.at(i);
      modest.at(i) %= MOD;
    }
    else{
      modest.at(i) = A.at(i);
    }
  }
  ll ans = 0;
  rep(i,N-1){
    ll wa = modest.at(N-1)-modest.at(i);
    wa=(wa+MOD)%MOD;
    ans += wa*A.at(i);
    ans %= MOD;
  }
  cout << ans << endl;
}
