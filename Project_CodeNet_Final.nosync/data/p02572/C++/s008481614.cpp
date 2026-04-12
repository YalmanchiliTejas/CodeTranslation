#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<bitset>
#include<queue>
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> vec(n);
  ll sum = 0;
  ll mod = 1000000007;
  rep(i,n){
    cin >> vec.at(i);
    sum += vec.at(i);
    sum %= mod;
  }
  ll ans;
  for (int i=0; i<n-1; i++){
    sum -= vec.at(i);
    if (sum < 0) sum += mod;
    ans += vec.at(i) * sum % mod;
  }
  cout << ans % mod << endl;
}
