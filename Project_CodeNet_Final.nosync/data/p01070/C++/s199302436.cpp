#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#define pb push_back
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = 1; i <= n; ++i)
#define drep(i,n) for (int i = (n)-1; i >= 0; --i)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define rng(x) x.begin(),x.end()
#define sz(x) int((x).size())
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;

const int MX = 100005;
const int INF = 1001001001;

struct seg {
  vector<vi> d; int x2;
  seg() {}
  seg(int mx) {
    x2 = 1; while (x2 < mx) x2 <<= 1;
    d = vvi(x2<<1);
  }
  void fil() {
    drep(i,x2) {
      d[i] = d[i<<1];
      d[i].insert(d[i].end(),rng(d[i<<1|1]));
      sort(rng(d[i]));
    }
  }
  int get(int a, int b, int x, int i=1, int l=0, int r=-1) {
    if (r == -1) r = x2;
    if (a <= l && r <= b) {
      return upper_bound(rng(d[i]),x)-d[i].begin();
    }
    int c = (l+r)>>1;
    int res = 0;
    if (a < c) res += get(a,b,x,i<<1,l,c);
    if (c < b) res += get(a,b,x,i<<1|1,c,r);
    return res;
  }
};

struct SA {
  string s;
  int n;
  vi id, rank, lcp;
  seg t;
  void cons() {
    s += '$';
    n = sz(s);
    id = rank = vi(n);
    vi tmp(n);
    rep(i,n) id[i] = i, rank[i] = s[i];
    int k;
    auto comp = [&](int i, int j) {
      if (rank[i] != rank[j]) return rank[i] < rank[j];
      int ri = i+k<sz(rank)?rank[i+k]:-1;
      int rj = j+k<sz(rank)?rank[j+k]:-1;
      return ri < rj;
    };
    for (k = 1; k < n; k <<= 1) {
      sort(rng(id),comp);
      tmp[id[0]] = 0;
      for (int i = 1; i < n; ++i) {
        tmp[id[i]] = tmp[id[i-1]] + comp(id[i-1],id[i]);
      }
      rank = tmp;
    }
    // cons_lcp();
    t = seg(n+5);
    rep(i,n) t.d[i+t.x2] = vi(1,id[i]);
    t.fil();
    // rep(i,n) cout<<i<<" "<<id[i]<<" "<<s.substr(id[i])<<endl;
  }
  // void cons_lcp() {
  //   lcp = vi(n);
  //   int h = 0;
  //   rep(i,n-1) {
  //     int j = id[rank[i]-1];
  //     if (h > 0) --h;
  //     for (; i+h < n && j+h < n && s[i+h] == s[j+h]; ++h);
  //     lcp[rank[i]-1] = h;
  //   }
  // }

  int getl(string &t) {
    int l = 0, r = n+1, c;
    while (l+1<r) {
      c = (l+r)>>1;
      if (s.compare(id[c],sz(t),t) < 0) l = c; else r = c;
    }
    return r;
  }
  int getr(string &t) {
    int l = -1, r = n, c;
    while (l+1<r) {
      c = (l+r)>>1;
      if (s.compare(id[c],sz(t),t) > 0) r = c; else l = c;
    }
    return l;
  }
  int f(int l, int r, int x) {
    int res = t.get(l,r,x);
    // cout<<l<<" "<<r<<" "<<x<<" "<<res<<endl;
    return res;
  }
};

char ss[MX];
string s;
int q;

int main() {
  scanf("%s",ss);
  SA sa;
  sa.s = ss;
  sa.cons();
  scanf("%d",&q);
  rep(qi,q) {
    int l, r;
    scanf("%d%d",&l,&r);
    scanf("%s",ss);
    string t = ss;
    r -= sz(t)-1;
    int a = sa.getl(t);
    int b = sa.getr(t)+1;
    // cout<<a<<" "<<b<<endl;
    int ans = 0;
    if (a < b && l <= r) ans = sa.f(a,b,r)-sa.f(a,b,l-1);
    printf("%d\n",ans);
  }
  return 0;
}