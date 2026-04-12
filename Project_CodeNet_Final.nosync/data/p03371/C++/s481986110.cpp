#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (b-1); i >= (a); i--)
#define REP(i,n) FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define DEBUG(x)  cout << #x << " = " << (x) << endl;
#define SORT(x) sort(ALL(x));
#define RSORT(x) sort(RALL(x));
#define SUM(x) accumulate(ALL(x),0);
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const ll mod = 1e9+7;
const int INF = (1<<30)-1;
const ll INFLL = (1LL<<62)-1;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main () {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

  int S1 = A*X + B*Y;
  int S2 = C*2*min(X,Y) + (X>=Y?A:B)*(max(X,Y)-min(X,Y));
  int S3 = C*2*max(X,Y);

  cout << min({S1,S2,S3}) << endl;
}