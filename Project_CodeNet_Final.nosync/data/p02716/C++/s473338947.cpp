#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

ll dp[200100][3];

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i){
  	cin >> a[i];
  }

  int x = n % 2 + 1;
  fill((ll*)dp, (ll*)dp + sizeof(dp) / sizeof(ll), -LINF);
  dp[0][0] = 0;

  for(int i = 0; i < n; ++i){
  	for(int j = 0; j <= x; ++j){
  		if(j < x)dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
  		ll cur = dp[i][j];
  		if((i + j) % 2 == 0)cur += a[i];
  		dp[i + 1][j] = max(dp[i + 1][j], cur);
  	}
  }

  cout << dp[n][x] << endl;
  return 0;
}
