#include <bits/stdc++.h>

using namespace std;
 
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
 
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
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define in(x, a, b) a <= x && x < b
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int n;
vl x, y;
std::random_device rnd;     // 非決定的な乱数生成器でシード生成機を生成
std::mt19937 mt(rnd()); //  メルセンヌツイスターの32ビット版、引数は初期シード
std::uniform_int_distribution<> rand100(1, 10);  

void rand_init() {
  n = rand100(mt);
  x.resize(n); y.resize(n);
  rep (i, n) {
    x[i] = rand100(mt);
    y[i] = rand100(mt);
    if (x[i] > y[i]) {
      swap(x[i], y[i]);
    }
  }
}

void init() {
  cin >> n;
  x.resize(n); y.resize(n);
  rep (i, n) {
    cin >> x[i] >> y[i];
    if (x[i] > y[i]) {
      swap(x[i], y[i]);
    }
  }
}
 
int main() {
  int n;
  cin >> n;
  vl x(n), y(n);
  ll ma = -INF, mi = INF;
  rep (i, n) {
    cin >> x[i] >> y[i];
    if (x[i] > y[i]) {
      swap(x[i], y[i]);
    }
    ma = max(ma, y[i]);
    mi = min(mi, x[i]);
  }
  if (ma == mi) {
    cout << 0 << endl;
    return 0;
  }
  //DEBUG(ma); DEBUG(mi);
  ll ans = INF;
 
  // when rmax == ma, bmin == mi
  ll rmax = ma, rmin = ma, bmax = mi, bmin = mi;
  rep (i, n) {
    rmin = min(rmin, y[i]);
    bmax = max(bmax, x[i]);
  }
  ans = (rmax - rmin) * (bmax - bmin);
  //cout << ans << endl;
 
  // rmax == ma, rmin == mi
  rmax = ma; rmin = mi;
  bmax = -INF, bmin = INF;
  rep (i, n) {
    if (x[i] == mi && y[i] == ma) {
      cout << ans << endl;
      return 0;
    }
    if (x[i] == mi) {
      bmax = max(bmax, y[i]);
      bmin = min(bmin, y[i]);
    }
    if (y[i] == ma) {
      bmax = max(bmax, x[i]);
      bmin = min(bmin, x[i]);
    }
  }
  //DEBUG(bmax); DEBUG(bmin);
 
  ll ans2 = INF;
  vector<bool> used(n);
  vector<pll> xy;
  int cnt = 0;
  rep (i, n) {
    if (x[i] == mi || y[i] == ma) {
      cnt++;
      continue;
    }
    if (in(x[i], bmin, bmax + 1) || in(y[i], bmin, bmax + 1)) {
      cnt++;
      continue;
    }
    else {
      if (bmax < x[i]) {
	cnt++;
	bmax = x[i];
      }
      else if (y[i] < bmin) {
	cnt++;
	bmin = y[i];
      }
    }
  }

  rep (i, n) {
    if (x[i] == mi || y[i] == ma) {
      cnt++;
      continue;
    }
    if (in(x[i], bmin, bmax + 1) || in(y[i], bmin, bmax + 1)) {
      cnt++;
      continue;
    }
    else {
      if (bmax < x[i]) {
	cnt++;
	bmax = x[i];
      }
      else if (y[i] < bmin) {
	cnt++;
	bmin = y[i];
      }
      else if (x[i] < bmin && bmax < y[i]) {
	xy.push_back(pll(x[i], y[i]));
      }
    }
  }
  sort(all(xy));
  rep (i, xy.size()) {
    ans2 = min(ans2, (rmax - rmin) * (bmax - xy[i].first));
    bmax = max(bmax, xy[i].second);
  }
  ans2 = min(ans2, (rmax - rmin) * (bmax - bmin));
  cout << min(ans, ans2) << endl;
}
 
 

/*
8
5 9
3 7
8 9
2 4
6 7
1 7
7 10
2 8
*/
