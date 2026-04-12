#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define imprime(v) for(int X=0;X<v.size();X++) printf("%d ", v[X]); printf("\n");
#define endl "\n"
const int INF= 0x3f3f3f3f;
const long double pi= acos(-1);
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vector< int > > vvi;
const int MOD=1e9+7;
const ll LINF=0x3f3f3f3f3f3f3f3f;
ll n;
ll a[55];

bool ok2(ull qte, ull k, ull v) {
  return (v + k + 1ll <= qte * (ull)n + n + qte);
  //return (v - qte * n + (k - qte) <= n - 1ll);
}

ll bb2(ll b, ll e, ll k, ll v) {
  if(b >= e) return b;
  ll mid = (b + e) / 2ll;
  if(ok2(mid, k, v)) return bb2(b, mid, k, v);
  return bb2(mid + 1ll, e, k, v);
}

bool ok(ll k) {
  ll qte = 0;
  for(int i = 0; i < n; i++) {
    ll tmp = bb2(0, k, k, a[i]);
    qte += tmp;
    if(!ok2(tmp, k, a[i])) return false;
  }
  return (qte <= k);
}

ll bb(ll b, ll e) {
  if(b >= e) return b;
  ll mid = (b + e) / 2ll;
  if(ok(mid)) return bb(b, mid);
  return bb(mid + 1ll, e);
}

int main() {
  cin>>n;
  for(int i = 0; i < n; i++) {
    cin>>a[i];
  }
  ll resp = bb(0ll, 520000000000000000ll);
  for(ll k = max(resp - 100000ll, 0ll); k <= (resp + 100000ll); k++) {
    if(ok(k)) {
      cout<<k<<endl;
      return 0;
    }
  }
  return 0;
}