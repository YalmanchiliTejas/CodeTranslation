#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-15;
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
const ll MOD1 = 998244353;
typedef pair<ll,ll> P;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define rrep(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,n) rep(i,0,n)
#define RREP(i,n) rrep(i,n,0)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

struct H {
  ll vote;
  string name;
  H(){vote = 0; name = "";}
  H(ll t, string c) {
    vote = t;
    name = c;
  }
  bool operator<(H e) const {
    if (vote == e.vote) return name > e.name;
    else return vote < e.vote;
  }
};

ll n,m,k,l;
vector<H> a;
vector<H> other, me;
set<string> st;

bool ok(ll K) {
  if (k < K) return 0;
  if (k - K >= sz(other)) return 1;
  H line = other[k - K];
  ll cnt = 0;
  REP(i,K) {
    ll vote = me[i].vote;
    string name = me[i].name;
    if (vote > line.vote) continue;
    else if (vote == line.vote) {
      if (name < line.name) continue;
      else cnt++;
    } else {
      cnt += line.vote - vote;
      if (name > line.name) cnt++;
    }
  }
//  cout << endl;
//  cout << "*" << line.vote << " " << line.name << endl;
//  cout << K << " " << cnt << " " << (cnt <= l? "ok":"no") <<endl;
  return cnt <= l;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> m >> k >> l, n) {
  other.clear();
  me.clear();
  st.clear();
  a.clear();

  REP(i,n) {
    string s;
    ll v;
    cin >> s >> v;
    a.pb(H(v,s));
  }
  sort(a.rbegin(),a.rend());
//
//  REP(i,n) {
//    cout << a[i].vote << " " << a[i].name << endl;
//  }

  REP(i,m) {
    string s;
    cin >> s;
    st.insert(s);
  }

  REP(i,n) {
    if (st.count(a[i].name)) {
      me.pb(a[i]);
    } else {
      other.pb(a[i]);
    }
  }

  other.pb({0,"zzz"});

  ll left = 0, r = m;
  while (left < r) {
    ll mid = (left + r + 1) / 2;
    if (ok(mid)) {
      left = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << left << endl;
  }
  return 0;
}

