
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}


typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// #define mp make_pair
//#define endl '\n'

// 1825

ll gcd(ll a, ll b) {
  if (b > a) {
    swap(a, b);
  }
  ll r = a%b;
  while (r != 0) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return (a / gcd(a, b))*b;
}

int n;
bool check(int a, int b) {
  int g = gcd(a, b);
  int a2 = a / g, b2 = b / g;
  if (a2 != b2 + 1) return true;
  int k = a2;
  if (k * a - (k - 1) * b < n - 1) return false;
  else return true;
}

int main() {
  cin >> n;
  vl s(n);
  rep (i, n) cin >> s[i];
  vector<pii> ab;
  rep1 (a, n - 1) {
    for (int j = 1; j*j <= (n - 1) - a; j++) {
      if ((n - 1 - a) % j == 0) {
        int c1 = j, c2 = (n - 1 - a) / j;
        int b1 = a - c1, b2 = a - c2;
        if (b1 >= 1 and b1 < a and check(a, b1)) {
          ab.push_back(pii(a, b1));
        }
        if (b2 >= 1 and b2 < a and b2 != b1 and check(a, b2)) {
          ab.push_back(pii(a, b2));
        }
      }
    }
  }
  //DEBUG(ab.size());
  //DEBUG_VEC(ab);
  sort(all(ab));
  int ma = 0;
  vii sa(n / 2 + 10);
  rep (i, ab.size()) {
    sa[ab[i].first - ab[i].second].push_back(ab[i].first);
  }
  //DEBUG_MAT(sa);

  ll ans = 0;
  rep (i, sa.size()) {
    if (sa[i].size() == 0) continue;
    ll sum = 0;
    int r = sa[i].back();
    int l = i;
    rrep (j, sa[i].size()) {
      sum += s[r] + s[l];
      chmax(ans, sum);
      r -= i;
      l += i;
    }
  }
  cout << ans << endl;
}
