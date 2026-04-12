#include <bits/stdc++.h>
using namespace std;
// define
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (a * b) % mod
#define rollcall cout << "I'm Sucu." << endl;
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define fi first
#define se second
// debug
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p){
  os << "(" << p.first << "," << p.second << ")";return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
  for (auto it = v.begin();it != v.end();++it){
    if(it != v.begin())os << " ";os << *it;
      }return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &mp){
  for(auto x: mp)os << "(" << x.first << "," << x.second << ")" << endl;
  return os;
}
template<typename T, int SIZE>
int array_length(const T (&)[SIZE]){return SIZE;}
template<typename T, int N>
void PRINTF(const T (&a)[N], int s = N, int t = -1, bool f = true){
	if(t == -1){rep(i,s){if(i)cout << " ";cout << a[i];}}
	else repi(i,s,t){if(i!=s)cout << " ";cout << a[i];}
	if(f)cout << "\n";
}
template<typename T, int N1, int N2>
void PRINTF(const T (&a)[N1][N2], int h = N1, int w = N2){
	rep(i,h){rep(j,w){cout << a[i][j] << " \n"[j==w-1];}}
}
// typedef
typedef complex<double> Point;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;


int f[200], s[200];
void init(){
  f[0] = 1;
  rrep(i,50){
    f[i] = 2*f[i-1]+1;
  }
  s[0] = 1;
  rrep(i,50){
    s[i] = 2*s[i-1]+3;
  }
}

int solve(int x, int L){
  int l = s[L-1];
  if(L == 0)return 1;
  if(x <= 1)return 0;
  if(x == l+2)return f[L-1]+1;
  if(x == s[L])return f[L];
  if(x < l+2)return solve(x-1, L-1);
  if(x > l+2)return f[L-1]+1+solve(x-l-2, L-1);
  return 0;
}

signed main(){
  init();
  int n, X;
  scanf("%lld%lld", &n, &X);
  int ans = solve(X, n);
  printf("%lld\n", ans);
  return 0;
}




