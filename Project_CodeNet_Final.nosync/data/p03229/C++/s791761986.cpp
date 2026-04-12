#include <bits/stdc++.h>
using namespace std;


/* エイリアス */
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define endl '\n'

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair


/* 関数マクロ */
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n, m) for (ll i = n; i <= m; ++i)
#define rep3(i, n, m) for (ll i = n; i >= m; --i)
#define all(v) v.begin(), v.end()
#define si(v) int(v.size())
#define UNIQUE(v) sort(all(v)), v.erase(unique(all(v)),v.end())


/* 定数 */
const ll mod = 1e9 + 7;
const ll infll = (1LL << 62) - 1;
const ll inf = (1LL << 30) - 1;


/* その他 */
template<class S, class T> inline bool chmax(S &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class S, class T> inline bool chmin(S &a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n; cin >> n;
  deque<ll> que;

  rep(i, n) {
    ll a; cin >> a;
    que.push_back(a);
  }

  sort(all(que));
  deque<ll> ans;

  ans.push_front(que.front()); que.pop_front();

  while (!que.empty()) {
    if (si(que) == 1) {
      ll v = que.front(); que.pop_front();
      if (abs(v - ans.back()) < abs(v - ans.front())) ans.push_front(v);
      else ans.push_back(v);
      break;
    }

    ll left = que.front(); que.pop_front();
    ll right = que.back(); que.pop_back();

    ll l = max(abs(left - ans.front()), abs(left - ans.back()));
    ll r = max(abs(right - ans.front()), abs(right - ans.back()));

    if (l < r) {
      que.push_front(left);
      if (abs(right - ans.front()) < abs(right - ans.back())) ans.push_back(right);
      else ans.push_front(right);
    } else {
      que.push_back(right);
      if (abs(left - ans.front()) < abs(left - ans.back())) ans.push_back(left);
      else ans.push_front(left);
    }
  }

  ll sum = 0;
  ll v = ans.front(); ans.pop_front();
  while (!ans.empty()) {
    ll a = ans.front(); ans.pop_front();
    sum += abs(v - a);
    v = a;
  }

  cout << sum << endl;
}
