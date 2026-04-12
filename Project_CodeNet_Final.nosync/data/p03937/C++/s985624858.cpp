#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())
#define pqasc priority_queue<long long, vector<long long>, greater<long long>>

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

class UnionFind{
private:
  vector<int> Parent; 
 public:
  UnionFind(int N){
    Parent = vector<int>(N, -1);
  }
  
  int root(int A){
    if(Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }
  
  int size(int A){
    return -Parent[root(A)]; 
  }
  
  bool connect(int A, int B){
    A = root(A);
    B = root(B);
    if(A == B){
      return false;
    }
    if(size(A) < size(B)) swap(A, B);
    Parent[A] += Parent[B];
    Parent[B] = A;
    return true;
  }
  
  bool isSame(int A, int B){
    return root(A) == root(B);
  }
};

long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

long long ngcd(vector<long long> a) {
  long long res = a[0];
  for(int i=1; i<a.size() && res!=1; i++) res = gcd(a[i], res);
  return res;
}

long long nlcm(vector<long long> a){
  long long res = a[0];
  for(int i=1; i<a.size(); i++) res = lcm(a[i], res);
  return res;
}

bool is_prime(long long n) {
  if(n < 2) return false;
  for (long long i = 2; i * i <= n; i++) if (n % i == 0) return false;
  return true;
}

int digsum(int n) {
  int res=0;
  while(n) res += n%10, n /= 10;
  return res;
}

int digcnt(int n){
  int res=0;
  while(n) res++, n /= 10;
  return res;
}

vector<int> divisor(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    (a *= a) %= mod;
    n >>= 1;
  }
  return res;
}

long long comb(long long a, long long b, long long mod){
  long long res = 1;
  for (long long i = a; i > a - b; i--) res = res * i % mod;
  for (long long i = 1; i <= b; i++) res = (res * modpow(i, mod-2, mod)) % mod;
  return res;
}

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

const int INF = 1e9;
const int MOD = 998244353;
const ll LINF = 1e18;

long long fact(int a){
  long long res=1;
  for(int i=1; i<=a; i++) (res *= i) %= MOD;
  return res;
}

void add(long long& a, long long b){
  a = (a+b) % MOD;
}

void mul(long long& a, long long b){
  a = (a*b) % MOD;
}

char G[10][10];

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int h,w; cin>>h>>w;
  rep(i,h) rep(j,w) cin>>G[i][j];
  
  bool ok=true;
  vi dy={0,0,-1,-1};
  vi dx={0,1,1,0};
  
  rep(y,h) rep(x,w){
    bool flg=true;
    rep(i,4){
      int ny=y+dy[i];
      int nx=x+dx[i];
      if(!inside(ny,nx,h,w)) false;
    }
    if(flg){
      if(G[y][x]=='.'&&G[y][x+1]=='#'&&G[y+1][x]=='#'&&G[y+1][x+1]=='#') ok=false;
      if(G[y][x]=='#'&&G[y][x+1]=='#'&&G[y+1][x]=='#') ok=false;
    }
  }
  if(ok) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}