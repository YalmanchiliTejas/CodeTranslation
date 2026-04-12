#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}
ll dp[110][2][4];
void solve(string N, long long K){
  ll n = N.size();
  dp[0][0][0] = 1;
  for(ll i=0; i<n; i++) {
    ll D = N[i]-'0';
    for(ll j=0; j<2; j++) {
      for(ll k=0; k<=K; k++) {
	for(ll d=0; d <= (j ? 9 : D); d++) {
	  if(k==K and d!=0) continue;
	  dp[i+1][j || (d < D)][k + (k<K and d!=0)] += dp[i][j][k];
	}
      }
    }
  }
  std::cout << dp[n][0][K]+dp[n][1][K] << std::endl;
}

int main(){
  string N;
  cin >> N;
  long long K;
  scanf("%lld",&K);
  solve(N, K);
  return 0;
}

