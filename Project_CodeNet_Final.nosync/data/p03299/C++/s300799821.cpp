#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;
const ll mod = 1000000007;
constexpr ll INF = 1000000000000000ll;

struct Mod {
  ll n;
  Mod () : n(0) {;}
  Mod (ll m) : n(m) {
    if (n >= mod) n %= mod;
    else if (n < 0) n = (n % mod + mod) % mod;
  }
  operator ll() { return n; }
};

bool operator==(Mod a, Mod b) { return a.n == b.n; }
Mod operator+=(Mod &a, Mod b) { a.n += b.n; if (a.n >= mod) a.n -= mod; return a; }
Mod operator-=(Mod &a, Mod b) { a.n -= b.n; if (a.n < 0) a.n += mod; return a; }
Mod operator*=(Mod &a, Mod b) { a.n = (a.n * b.n) % mod; return a; }
Mod operator+(Mod a, Mod b) { return a += b; }
Mod operator-(Mod a, Mod b) { return a -= b; }
Mod operator*(Mod a, Mod b) { return a *= b; }
Mod operator^(Mod a, ll n) {
  if (n == 0) return Mod(1);
  Mod res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}

Mod pow2(ll n) {
  return Mod(2) ^ n;
}

int main()
{
  ll n;
  cin>>n;
  vector<ll> h(n+2);
  REP(i,n) cin>>h[i+1];
  vector<Mod> dpa(n, 2), dpb(n, 0);
  set<ll> sh;
  REP(i,n) {
    sh.insert(h[i+1]);
    if (h[i] == h[i+1]) {
      dpb[i] = Mod(2)*dpb[i-1] + Mod(2);
    }
  }
  for_each(rbegin(sh), rend(sh), [&](ll hi) {
    set<int> pos;
    REP(i,n) {
      if (h[i+1] == hi) {
        pos.insert(i);
      }
    }
    for (int p : pos) {
      int l, r;
      for (l = p-1; l >= 0; --l) {
        if (h[l+1] < hi) break;
      }
      for (r = p+1; r < n; ++r) {
        if (h[r+1] < hi) break;
      }
      bool old = false, old2 = true;
      vector<ll> minh(1, INF);
      int cnt = 0;
      vector<Mod> vdpa, vdpb;
      FOR(i,l+1,r) {
        if (h[i+1] == hi) {
          if (!old2) {
            minh.push_back(INF);
          }
          old = false;
          old2 = true;
          ++cnt;
          continue;
        }
        if (h[i+1] <= minh.back()) {
          minh.back() = h[i+1];
          if (old) {
            vdpa.back() = dpa[i];
            vdpb.back() = dpb[i];
          } else {
            vdpa.emplace_back(dpa[i]);
            vdpb.emplace_back(dpb[i]);
          }
          old = true;
          old2 = false;
        }
      }
      if (vdpa.empty()) continue;
      Mod a = 1;
      REP(i, vdpa.size()) {
        a *= vdpa[i] * pow2(minh[i] - hi - 1);
      }
      Mod b = 1;
      REP(i, vdpa.size()) {
        b *= Mod(2)*(vdpa[i] * pow2(minh[i] - hi - 1)) + vdpb[i];
      }
      Mod mb = 1;
      REP(i, vdpa.size()) {
        mb *= Mod(2)*(vdpa[i] * pow2(minh[i] - hi - 1));
      }
      cerr << p << ' ' << a << ' ' << b << ' ' << mb << ' ' << cnt << endl;
      b -= mb;
      dpa[p] = a*Mod(2);
      dpb[p] = a * (pow2(cnt+vdpa.size()) - Mod(2)) + b * pow2(cnt);
    }
  });
  int mn = 0;
  ll mnh = INF;
  REP(i,n) {
    cerr << dpa[i] << ' ' << dpb[i] << endl;
    if (h[i+1] <= mnh) {
      mnh = h[i+1];
      mn = i;
    }
  }
  cout << dpa[mn] * pow2(mnh-1) + dpb[mn] << endl;
  return 0;
}
