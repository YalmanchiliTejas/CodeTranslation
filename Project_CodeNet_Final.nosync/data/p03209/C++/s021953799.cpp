#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int INF = 1000000007;
int N;
ll X;
ll P[53], S[53];


ll dfs(int n, ll x){ // レベルnバーガーの下からx番目の層にあるぱてぃの個数
  if (x==1) return n==0?1ll:0ll;
  else if (x<= 1+S[n-1]) return dfs(n-1, x-1);
  else if (x==2+S[n-1]) return P[n-1] + 1ll;
  else if (x<=2+2*S[n-1]) return P[n-1] + 1ll + dfs(n-1, x-2ll-S[n-1]);
  else return 2*P[n-1]+1ll;
}


int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> X;
  P[0] = 1ll;
  S[0] = 1ll;
  rep(i, N-1){
    P[i+1] = 2*P[i]+1ll;
    S[i+1] = 2*S[i]+3ll; 
  }

  cout << dfs(N, X) << "\n";
  return 0;
}
