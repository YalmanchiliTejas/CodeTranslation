#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<ll> ql;
typedef deque<ll> dql;
typedef priority_queue<ll/*, vl, greater<ll>*/> pql; //降順(/*昇順*/)
typedef set<ll> sl;
typedef pair<ll, ll> pl;
typedef pair<pl, ll> ppl;
typedef vector<vl> vvl;
typedef vector<pl> vpl;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rep2(i, k, n) for(ll i = ll(k); i <= ll(n); i++)
#define rep3(i, n, k) for(ll i = ll(n); i >= ll(k); i--)
#define all(v) (v).begin(), (v).end()
ll mod(ll a, ll b) {if(b == 0) return 0; return (a % b + b) % b;}
bool chmin(ll &a, ll b) {if(b < a) {a = b; return 1;} return 0;}
bool chmax(ll &a, ll b) {if(b > a) {a = b; return 1;} return 0;}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const ll MAX = 1e9;
const char newl = '\n';

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, x, m;
  cin >> n >> x >> m;

  vl first(m, INF);
  first[x] = 1;

  ll ans = x;
  vl sum(2);
  sum[1] = x;
  rep2(i, 2, n) {
    x *= x;
    x %= m;

    if(first[x] == INF) {
      first[x] = i;
      sum.push_back(sum.back() + x);
      ans += x;
    }else {
      ll loop_size = i-first[x];
      ll loop_sum = sum[i-1] - sum[first[x]-1];
      ans += (n-i+1)/loop_size*loop_sum;
      rep(_, (n-i+1)%loop_size) {
        ans += x;
        x *= x;
        x %= m;
      }
      break;
    }
  }

  cout << ans << newl;
  return 0;
}