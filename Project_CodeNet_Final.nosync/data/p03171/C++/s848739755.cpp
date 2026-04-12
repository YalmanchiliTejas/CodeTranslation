#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvb vector<vb>
#define vvd vector<vd>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define pb push_back
#define sz(s) (int)(s.size())

#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll keta(ll n){
  string s = to_string(n);
  ll num = s.size();
  return num;
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w){}
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;

class UnionFind{
public:
  vi Parent, diff_weight;
  UnionFind(int n){
    Parent = vi(n,-1);
    diff_weight = vi(n,0);
  }

  int root(int a){
    if(Parent[a] < 0) return a;
    int r = root(Parent[a]);
    diff_weight[a] += diff_weight[Parent[a]];
    return Parent[a] = r;
  }

  int weight(int a){
    root(a);
    return diff_weight[a];
  }

  bool issame(int a, int b){
    return root(a) == root(b);
  }

  int size(int a){
    return -Parent[root(a)];
  }

  // weight(b) - weight(a) = w となるように繋ぐ
  // 数直線上で a........b となっていてその距離が w 、のようなイメージ
  bool merge(int a, int b, int w = 0){
    w += weight(a); w -= weight(b);

    a = root(a);
    b = root(b);

    if(a == b) return false;

    if(size(a) < size(b)) swap(a,b), w = -w;
    Parent[a] += Parent[b];
    Parent[b] = a;
    diff_weight[b] = w;
    return true;
  }

  int diff(int a, int b){
    return weight(b) - weight(a);
  }
};

vi MP(string s){
  vi A(s.size()+1);
  A[0] = -1;
  int j = -1;
  rep(i,s.size()) {
    while(j >= 0 && s[i] != s[j]) j = A[j];
    j++;
    A[i+1] = j;
  }
  return A;
}

vi Manacher(string s){
  vi R(s.size());
  int i = 0, j = 0;
  while(i < s.size()){
    while(i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]) ++j;
    R[i] = j;
    int k = 1;
    while(i-k >= 0 && i+k < s.size() && k+R[i-k] < j) R[i+k] = R[i-k], k++;
    i += k; j -= k;
  }
  return R;
}

vi Z_algorithm(string &s){
  vi Z(s.size());
  Z[0] = s.size();
  int i = 1, j = 0;
  while(i < s.size()){
    while(i+j < s.size() && s[j] == s[i+j]) j++;
    Z[i] = j;
    if(j == 0){++i; continue;}
    int k = 1;
    while(i+k < s.size() && k+Z[k] < j) Z[i+k] = Z[k], ++k;
    i += k; j -= k;
  }
  return Z;
}

const int MAX = 1e6+1;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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

// 二項係数計算
long long COM(ll n, ll k){
  if(n >= MAX){
    ll tmp = 1;
    rep(i,k){
      tmp *= (n-i);
      tmp %= MOD;
    }
    return tmp*finv[k]%MOD;
  }

  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll POW(ll x, ll n){
  ll ret = 1;
  if(n < 0){// n < 0 にも対応
    n *= -1;
    x = inv[x];
  }
  while(0 < n){
    if(n%2 == 0){
      x = x*x%MOD;
      n /= 2;
    }
    else{
      ret = ret*x%MOD;
      n--;
    }
  }
  return ret;
}

ll a[3030];
ll dp[3030][3030];
int flag[3030][3030];
// dp[i][j] : 区間 [i,j] が残ってる時の「(自分の点数)-(相手の点数)」の最小値

ll f(int l, int r){
  if(flag[l][r]) return dp[l][r];
  if(l == r) return a[r];
  flag[l][r] = 1;
  dp[l][r] = max(a[l] - f(l+1,r), a[r] - f(l,r-1));
  // printf("l:%d r:%d dp[l][r]:%lld\n", l, r, dp[l][r]);
  return dp[l][r];
}

int main(){
  int n; cin >> n;
  rep(i,n) cin >> a[i];
  memset(flag, 0, sizeof(flag));
  cout << f(0,n-1) << endl;
}
