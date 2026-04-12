#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repf(i,a,b) for (int i = (a); i < (b); i++)
#define repi(i,a,b) for (int i = (a); i <= (b); i++)
#define repr(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SORT(x) sort(all(x));
#define RSORT(x) sort(rall(x));
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using tiii = tuple<int, int, int>;
const ll inf = 1ll<<29;
const ll mod = 1000000007;      
const double eps = 1e-9;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int N; cin >> N;
  vi H(N); rep(i,N) cin >> H.at(i);

  int ans = 1;
  int max_H = 0;
  repf(i,1,N) {
    max_H = max(max_H,H.at(i-1));
    if(max_H <= H.at(i)) ans++;
  }
  cout << ans << endl;
}