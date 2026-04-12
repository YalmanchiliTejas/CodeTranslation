#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define SUM(c) accumulate((c).begin(),(c).end(),0)
#define ALL(a)  (a).begin(),(a).end()


long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> T maxt(T x,T y) {
    if (x>y) return x;
    else return y;
}
template<class T> T mint(T x,T y) {
    if (x>y) return y;
    else return x;
}
//sort(v.rbegin(), v.rend(), [](auto& x, auto& y){return x[1] < y[1];});
//cout << fixed << setprecision(10) << ans << defaultfloat << endl;


//小数出力
double print_double(double d){printf("%.10f", d);}

long long m = 1e9+7, mod = 1e9+7;

//逆元　a/b の modをとるとき -> a*modinv(b)%mod
long long modinv(long long a, long long m = 1e9+7) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

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


//Union Find
struct UnionFind {
    vector<int> par; // 親ノード
    vector<int> rank; // ランク

    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n); rank.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};





ll combination_mod(int n, int k) {
  k = mint(k,n-k);
  ll ans = 1;
  if (n==0 || k ==0) return ans;
  rep(i,k) {
    ans = ans*(n-i)%mod;
    ans = ans*modinv(i+1)%mod;
  }
  return ans;
}

struct edge {
  int from; //出発点
  int to;   //到達点
  int cost; //移動コスト
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


ll _pow(ll a, ll b) {
  ll ans = 1;
  rep(i,b) ans*=a;
  return ans;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
  ll N,M,K,an=0,am=0;
  cin >> N >> M >> K;

  FOR(i,1,N) {
    an += i*(N-i)*M*M%mod;
  }
  
  FOR(i,1,M) {
    am += i*(M-i)*N*N%mod;
  }
  COMinit();
  ll ans = (an+am)%mod*COM(N*M-2,K-2)%mod; 
  cout << ans << endl;


}