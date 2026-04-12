#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define pb push_back
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = 1; i <= n; ++i)
#define drep(i,n) for (int i = (n)-1; i >= 0; --i)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define rng(x) x.begin(),x.end()
#define sz(x) int((x).size())
using namespace std;
typedef vector<int> vi;

const int MX = 100005;
const int INF = 1001001001;

int n, a, df, q, p;
vi x, l, r;

int main() {
  scanf("%d%d%d%d",&n,&a,&df,&q);
  x = l = r = vi(q);
  rep(i,q) {
    scanf("%d%d%d",&x[i],&l[i],&r[i]);
  }
  scanf("%d",&p);
  vi d;
  drep(i,q) {
    if (x[i] == 0) {
      if (l[i] <= p && p <= r[i]) p = r[i]-(p-l[i]);
    } else if (x[i] == 1) {
      if (l[i] <= p && p <= r[i]) d.pb(1);
    } else {
      if (l[i] <= p && p <= r[i]) d.pb(0);
    }
  }
  reverse(rng(d));
  int ans = a+df*p-df;
  for (int k : d) {
    if (k) ans++; else ans /= 2;
  }
  cout<<ans<<endl;
  return 0;
}