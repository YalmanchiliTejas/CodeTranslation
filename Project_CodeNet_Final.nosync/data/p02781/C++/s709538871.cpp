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
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>a
#define pb push_back
#define sz(x) int(x.size())

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
  vi Parent;
  UnionFind(int n){
    Parent = vi(n,-1);
  }

  int root(int a){
    if(Parent[a] < 0) return a;
    else return Parent[a] = root(Parent[a]);
  }

  int size(int a){
    return -Parent[root(a)];
  }

  bool merge(int a, int b){
    a = root(a);
    b = root(b);
    if(a == b) return false;

    if(size(a) < size(b)) swap(a,b);
    Parent[a] += Parent[b];
    Parent[b] = a;

    return true;
  }
};

class Factrial{
public:
  vl Fac;
  Factrial(int MAX){
    Fac = vl(MAX+1);
    rep(i,MAX) {
      if(i == 0) Fac[i+1] = 1;
      else Fac[i+1] = ((i+1)*Fac[i])%MOD;
    }
  }
};

const int MAX = 1000;
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int power(int k){
  int tmp = 1;
  rep(i,k) tmp *= 9;
  return tmp;
}

int dfs(string s, int k){
  int n = sz(s);
  if(k == 0){
    return 1;
  }
  if(n == 0){
    return 0;
  }
  int top = s[0]-'0';
  int ret = 0;
  //printf("n:%d k:%d com:%d pow:%d\n", n, k, COM(n-1,k), power(k));
  if(top != 0){
    ret += COM(n-1,k)*power(k) + max(top-1,0) * COM(n-1,k-1) * power(k-1);
    s.erase(s.begin());
    ret += dfs(s, k-1);
    return ret;
  }
  else{
    s.erase(s.begin());
    return dfs(s, k);
  }

}

int main(){
  string N; int k;
  cin >> N >> k;
  int n = N.size();

  COMinit();

  vi a(n+1),b(n+1);

  //cout << n*(n-1)*(n-2)/6*9*9*9 << endl;
  cout << dfs(N,k) << endl;
}
