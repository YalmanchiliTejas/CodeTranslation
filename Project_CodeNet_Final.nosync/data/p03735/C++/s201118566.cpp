#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> point;

const int MAXN = 2e5 + 5;

int n;
point a[MAXN];
ll sol;
multiset <int> l, r;

void probaj(){
  ll minix = *l.begin();
  ll miniy = *r.begin();
  auto it = l.end(); it --;
  ll maxix = *it;
  it = r.end(); it --;
  ll maxiy = *it;

  ll nsol = (maxix - minix) * (maxiy - miniy);
  sol = min(sol, nsol);
}

bool cmp(point A, point B){
  if(A.second != B.second) return A.second > B.second;
  return A.first > B.first;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  sol = 1e18;

  cin >> n;
  REP(i, n){
    cin >> a[i].first >> a[i].second;
    if(a[i].first > a[i].second) swap(a[i].first, a[i].second);
    l.insert(a[i].first); r.insert(a[i].second);
  }
  sort(a, a + n);
  probaj();
  REP(i, n){
    l.erase(l.find(a[i].first));
    r.erase(r.find(a[i].second));
    swap(a[i].first, a[i].second);
    l.insert(a[i].first);
    r.insert(a[i].second);
    probaj();
  }

  cout << sol;
}
