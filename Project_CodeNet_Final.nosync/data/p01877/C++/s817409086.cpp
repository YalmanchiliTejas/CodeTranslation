#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define rng(x) x.begin(),x.end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vp;

struct seg {
  int x2;
  vi d;
  vp e;
  seg() {}
  seg(int mx) {
    x2 = 1;
    while (x2 < mx) x2 <<= 1;
    d = vi(x2<<1);
    e = vp(x2<<1);
  }
  P f(P a, P b, int w) {
    if (a.fi == b.fi) {
      return P(a.fi,a.se+b.se);
    } else {
      a = max(a,b);
      a.se += w/2;
      return a;
    }
  }
  void add(int a, int b, int x, int i=1, int l=0, int r=-1) {
    if (r == -1) r = x2;
    if (a <= l && r <= b) {
      d[i] += x;
      e[i].fi += x;
      return;
    }
    int c = (l+r)>>1;
    int li = i<<1, ri = li|1;
    if (a < c) add(a,b,x,li,l,c);
    if (c < b) add(a,b,x,ri,c,r);
    e[i] = f(e[li],e[ri],r-l); e[i].fi += d[i];
  }
};

int main() {
  int n;
  scanf("%d",&n);
  vi a(n);
  rep(i,n) scanf("%d",&a[i]);
  int q;
  scanf("%d",&q);
  seg t(n+5);
  rep(i,n/2) {
    t.add(i,i+1,a[i]);
  }
  rep(i,n/2) {
    t.add(i,i+1,-a[n-1-i]);
  }
  rep(qi,q) {
    int l, r, x;
    scanf("%d%d%d",&l,&r,&x);
    --l;
    // cout<<qi<<" "<<l<<" "<<r<<" "<<x<<endl;
    if (l < n/2) {
      int a = l, b = min(r,n/2);
      // cout<<a<<" "<<b<<endl;
      t.add(a,b,x);
    }
    if (r >= n/2) {
      int a = n-max(l,n/2), b = n-r;
      // cout<<a<<" "<<b<<endl;
      t.add(b,a,-x);
    }
    if (t.e[1].se) printf("%d\n",0);
    else printf("%d\n",1);
  }
  return 0;
}