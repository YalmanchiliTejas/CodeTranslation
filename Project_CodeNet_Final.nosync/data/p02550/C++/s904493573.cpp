#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
 
#define sz(x) (int)(x).size()
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define sor(x) sort(all(x))
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define endl '\n'
 
const ll MOD = 998244353;
const ll INF = 1e18;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   ll n, x; int m; cin >> n >> x >> m;
   vi a;
   unordered_set<int> used;
   while (used.count(x) == 0) {
      a.pb(x);
      used.insert(x);
      x = x * x % m;
   }
   int s = 0;
   while (a[s] != x)
      s++;
   ll ans = 0;
   for (int i = 0; i < s; i++)
      ans += a[i];
   ll q = (n - s) / (sz(a) - s);
   int r = (n - s) % (sz(a) - s);
   for (int i = 0; i < r; i++)
      ans += a[s + i];
   ll cur = 0;
   for (int i = s; i < sz(a); i++)
      cur += a[i];
   ans += q * cur;
   cout << ans;
   return 0;
}