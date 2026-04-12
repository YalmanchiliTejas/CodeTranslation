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
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
string S;
int K;

// Nは桁数, countは0でないものの個数。これらが決まったときにあり得る数の個数(n C countで求まる)
ll combi(ll N, int count) {
  if (count == 1) return N*9ll;
  if (count == 2) return 81ll*N*(N-1)/2;
  if (count == 3) return 729ll*N*(N-1)*(N-2)/6;
  else return 0ll;
}
// i 桁目以降について、0 以外の値を残り K 個使用可能という状況を考える。
// このとき i 桁目までの部分が「等しい」か「strict に小さくなっている」かを smaller フラグによって分岐する。
ll dfs(int idx, int k, bool smaller) {
  if (k==0) return 1ll; // 以下全部0
  if (smaller) return combi((ll)S.size()-idx, k);
  if (idx==S.size()) {
    if (k==0) return 1ll;
    else return 0ll;
  }
  if (S[idx]=='0') return dfs(idx+1, k, false);

  ll zero_count = dfs(idx+1, k, true);
  ll between_count = ll(S[idx] - '1') * dfs(idx+1, k-1, true);
  ll icchi_count = dfs(idx+1, k-1, false);
  return zero_count+between_count+icchi_count;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;
  cin >> K;
  
  cout <<  dfs(0, K, false) << "\n";
  return 0;
}