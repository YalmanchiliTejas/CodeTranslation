#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0;i < n;i++)
#define FOR(i, n, m) for(int i=n; i<m; ++i)

using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {
  ll N;
  ll A[200010];
  cin >> N;
  rep(i,N){
    cin >> A[i];
  }
  ll ans = 0;
  ll m = 1000000007;
  ll t[200010];
  
  t[0] = A[N-1];
  rep(i, N-2){
    t[i+1] = t[i] + A[N-2-i];
    t[i+1] %= m;
  }
  
  rep(i,N-1){
      ans += A[i]*t[N-i-2];
      ans %= m;
  }

  cout << ans << endl;

  
}