#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <deque>
#include <map>

#define INF 200000000000
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;
using P = pair<long, long>;

/*
const int MAX = 1000000;
const int MOD = 1000000007;


long long fac[MAX], finv[MAX], inv[MAX];

//テーブルの前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        //そのまま計算すると負の値になるのでMODを足す
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//二分累乗法
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
*/

/*
//UnionFind木
struct UnionFind{
   vector<long long int> par; //par[i] : iの親の番号
   vector<long long int> rnk; //root[i] : iの木のサイズ

   //コンストラクタ
   UnionFind(long long int n): par(n), rnk(n){
       //木の初期化
       for(long long int i = 0; i < n; i++){
           par[i] = i;
           rnk[i] = 1;
       }
   }

   //データxが属する木の根を再帰で取得
   long long int root(long long int x){
       if(par[x] == x){
           return x;
       }else{
           return par[x] = root(par[x]);
       }
   }

   //xとyが同じ木に属しているかを判定
   bool same(long long int x, long long int y){
       return root(x) == root(y);
   }

   //xとyの木を併合
   void unite(long long int x, long long int y){
       long long int rx = root(x); //xの根
       long long int ry = root(y); //yの根
       if(rx == ry) return; //根が同じならそのまま

       //併合するときにサイズを足し合わせる
       if(rnk[rx] < rnk[ry]){
           par[rx] = ry;
           rnk[ry] += rnk[rx];
       }else{
           par[ry] = rx;
           rnk[rx] += rnk[ry];
       }
   }

   //属している木のサイズを取得
   long long int size(long long int x){
       return rnk[root(x)];
   }
};
*/

/*
//重み付きUnionFind
template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};
*/

/*
//ダイクストラ
typedef struct edge{
   int to;
   int cost;
} edge;

vector<edge> graph[2010];
long long int d[2010];

void dijkstra(int s){
   priority_queue<P, vector<P>, greater<P> > que;
   for(int i = 0; i < 2010; i++){
       d[i] = INF;
   }
   d[s] = 0;
   que.push(P(s, 0));

   while (!que.empty()) {
       P p = que.top();
       que.pop();
       int v = p.first;
       if (d[v] < p.second) continue;

       for (int i=0; i<graph[v].size(); ++i) {
           edge e = graph[v][i];
           if (d[e.to] > d[v] + e.cost) {
               d[e.to] = d[v] + e.cost;
               que.push(P(e.to, d[e.to]));
           }
       }
   }
}
*/

/*
#素因数分解
map<long long, long long> prime_factor(long long n) {
  map<long long, long long> ret;
  for(long long i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
*/

long long int digit(string s, int K){
    long long int dp[110][2][110] = {0};
    
    int n = s.size();
    
    dp[0][0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k <= n; k++){

                //次の位の数字がどこまでいけるか
                int lim;
                if(j == 1){
                    lim = 9;
                }else{
                    lim = s[i] - '0';
                }
                //次の位の数字を行ける範囲まで探索してdpを更新する
                for(int d = 0; d < lim+1; d++){
                    dp[i+1][j || d < lim][k + (d != 0)] += dp[i][j][k];
                }
            }
        }
    }
    
    return dp[n][0][K] + dp[n][1][K];
}

int main(){
    string n;
    int k;
    cin >> n >> k;
    long long int ans = digit(n, k);
    
    cout << ans << endl;
}