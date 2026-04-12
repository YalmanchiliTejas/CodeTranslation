#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define SUM(c) accumulate((c).begin(),(c).end(),0)
#define ALL(a)  (a).begin(),(a).end()
// int gcd(int a,int b){return b?gcd(b,a%b):a;}
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}

using namespace std;

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
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;

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
  vl cost_to(V,INF);
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


int main() {
  string N;
  ll K;
  cin >> N >> K;

  vector<vl> dp(N.size()+1,vl(4,0));
  dp[0][0] = 1;
  rep(i,N.size()) {
    int ni = N[N.size()-i-1] - '0';
    dp[i+1][0] = 1;
    dp[i+1][1] = dp[i][1] + 9;
    dp[i+1][2] = 9*dp[i][1] + dp[i][2];
    dp[i+1][3] = 9*dp[i][2] + dp[i][3];
  }
  vl memo;
  ll ans = 1;
  rep(i,N.size()) {
    if (N[i]!='0') {
      memo.push_back(N.size()-i);
      memo.push_back(N[i]-'0');
      if (memo.size()==2*K) break;
      }
    if (i==N.size()-1) {
      ans--;
    }
  }
  
  FOR(i,1,memo.size()/2+1) {
    ans += (memo[2*i-1]-1)*dp[memo[2*i-2]-1][K-i]+dp[memo[2*i-2]-1][K-i+1];
    // cout << ans << endl;
  }
  printf("%d", ans);
}
