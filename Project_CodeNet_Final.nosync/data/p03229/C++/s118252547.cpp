#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define SORT(x) sort(x.begin(),x.end())
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

int main() {
  int n;
  cin >> n;
  vi a(n);
  vi b(n);
  rep(i,n){
    cin >> a[i];
    b[i] = a[i];
  }
  SORT(a);
  sort(b.begin(),b.end(),greater<int>());
  
  int ai=1,bi=0;
  ll l = a[0], r = a[0];
  ll ans = 0;
  while(ai+bi < n){
    // show(ai);
    // show(bi);
    ll diff1 = max(abs(l-a[ai]),abs(r-a[ai]));
    ll diff2 = max(abs(l-b[bi]),abs(r-b[bi]));
    if(diff1 > diff2){
      ans+= diff1;
      if(abs(l-a[ai])> abs(r-a[ai])) l = a[ai];
      else r = a[ai];
      ai++;
    }else{
      ans+=diff2;
      if(abs(l-b[bi])> abs(r-b[bi])) l = b[bi];
      else r = b[bi];
      bi++;      
    }
  }
  cout<<ans<<endl;
  return 0;
}