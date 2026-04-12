#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod =1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> T maxt(T x,T y) {if (x>y) return x;else return y;}
template<class T> T mint(T x,T y) {if (x>y) return y;else return x;}
//sort(v.begin(), v.end(), [](auto& x, auto& y){return x[1] < y[1];});


//小数出力
// double print_double(double d){printf("%.6f", d);}

//約数列挙
vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}



// ll combination_mod(int n, int k) {
//   k = mint(k,n-k);
//   ll ans = 1;
//   if (n==0 || k ==0) return ans;
//   rep(i,k) {
//     ans = ans*(n-i)%mod;
//     ans = ans*modinv(i+1)%mod;
//   }
//   return ans;
// }

struct edge {
  int from; //出発点
  int to;   //到達点
  ll cost; //移動コスト
};

//ベルマンフォード法
vector<ll> bellman_ford (vector<edge> edges, int V, int E, int r, ll INF = 100000000000) {  
  vector<ll> cost_to(V,INF);
  cost_to[r] = 0;
  rep(i,V) {
    rep(j,E) {
      edge e = edges[j];
      if (cost_to[e.from]==INF) continue;
      if (cost_to[e.to] > cost_to[e.from] + e.cost) {
        cost_to[e.to] = cost_to[e.from] + e.cost;
        if (i==V-1) {
          printf("NEGATIVE CYCLE\n");
          return {};
        }
      }

    }
  }
  return cost_to;
}

// combination
const int MAX = 510000;
const int MOD = 1000000007;
 
long long fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


// 木上の探索
vector<int> cnt;
void dfs(const vector<vector<int>> &G, int v, int p) {
    for (auto nv : G[v]) {
        if (nv == p) continue; // nv が親 p だったらダメ
        dfs(G, nv, v);
    }

    // 帰りがけ時に、部分木サイズを求める
    cnt[v] = 1; // 自分自身
    for (auto c : G[v]) {
        if (c == p) continue;
        cnt[v] += cnt[c]; // 子のサイズを加える
    }
}

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  rep(i,N) cin >> a[i];
  vector<vector<ll>> dp(N,vector<ll> (N,0));
  rep(i,N){
    rep(j,N-i) {
      if (i==0) dp[i][j] = a[j];
      else {
        dp[i][j] = maxt(a[j]-dp[i-1][j+1],a[j+i]-dp[i-1][j]);
      }
      // cout << dp[i][j] << ' ';
    }
      // cout << endl;
    
  }
  cout << dp[N-1][0] << endl;
}
