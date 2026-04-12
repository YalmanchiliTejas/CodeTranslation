#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define fore(i, x, a) for(auto &&x:a) 
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define ALL(x) begin(x),end(x)
#define F first
#define S second
const int inf=1001001001; const long long INF=1001001001001001001;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vii = vector<int>;
using vll = vector<ll>;
template<class T>using  PS_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>using vv = vector<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){fill( (T*)array, (T*)(array+N), val );}
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T>T gcd(T a, T b){ return b ? gcd(b, a % b) : a; }
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct edge { int to, from, cost; };
int dy[]={0, 1, -1, 0}; int dx[]={1, 0, 0, -1};
//
//
//
//          ∧ ∧  ／￣￣￣￣￣￣￣￣￣￣￣＼
// ～′￣￣( ˚д˚)＜  Let's start coding!!  |
//  UU￣￣  U U  ＼                      ／
//                 ￣￣￣￣￣￣￣￣￣￣￣

ll n, k;
int main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
  cin >> n >> k;
  if (k == 0) {
    cout << n * n << endl;
    return 0;
  }
  ll ans = 0;
  erep(i, 1, n) {
    if (i >= k + 1) {
      ans += n / i * (i - k);
      ans += max(0LL, (n % i) - k + 1);
    }
  }
  cout << ans << endl;
  return 0;
}

