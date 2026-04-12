#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define fi first
#define se second
#define inf (INT_MAX/2-1)
#define infl (1LL<<60)
#define vi vector<int>
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) begin(a),end(a)
#define y0 y5656
#define y1 y7878
#define aaa system("pause");
#define dbg(x) cerr<<(#x)<<": "<<(x)<<'\n',aaa
#define dbga(x,n) cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)cerr<<x[_]<<' ';cerr<<'\n',aaa
#define dbgs(x) cerr<<(#x)<<"[stl]: ";for(int _:x)cerr<<_<<' ';cerr<<'\n',aaa
#define dbgp(x) cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa
#define maxn 200000

using namespace std;

struct yes { int l, r; ll scor; };

yes v[maxn+5], u[maxn+5];
ll d[maxn+5];///d[i]=scor maxim daca i este ultima pozitie cu 1 de la st la dr

void umax (ll &a, ll b) { a = max(a,b); }

struct sgtreel {
  sgtreel () {}
  ll yy[4*(maxn+1)+5], lazy[4*(maxn+1)+5];
  void updatel (int p, pii itv, pii ok, ll val) {
    if (lazy[p] != 0) {
      yy[p] += lazy[p];
      if (itv.fi < itv.se) {
        lazy[p*2] += lazy[p];
        lazy[p*2+1] += lazy[p];
      }
      lazy[p] = 0;
    }
    if (itv.fi > ok.se || ok.fi > itv.se) return;
    if (itv.fi >= ok.fi && itv.se <= ok.se) {
      yy[p] += val;
      if (itv.fi < itv.se) {
        lazy[p*2] += val;
        lazy[p*2+1] += val;
      }
      return;
    }
    int mid = (itv.fi + itv.se) / 2;
    updatel(p*2, {itv.fi, mid}, ok, val);
    updatel(p*2+1, {mid+1, itv.se}, ok, val);
    yy[p] = max(yy[p*2], yy[p*2+1]);
  }
  void preupdatel (pii ok, ll val) {///trb inclus si 0
    updatel(1, {1,maxn+1}, {ok.fi+1, ok.se+1}, val);
  }
  ll q_query;
  void queryl (int p, pii itv, pii ok) {
    if (lazy[p] != 0) {
      yy[p] += lazy[p];
      if (itv.fi < itv.se) {
        lazy[p*2] += lazy[p];
        lazy[p*2+1] += lazy[p];
      }
      lazy[p] = 0;
    }
    if (itv.fi > ok.se || ok.fi > itv.se) return;
    if (itv.fi >= ok.fi && itv.se <= ok.se) {
      umax(q_query, yy[p]);
      return;
    }
    int mid = (itv.fi + itv.se) / 2;
    queryl (p*2, {itv.fi, mid}, ok);
    queryl (p*2+1, {mid+1, itv.se}, ok);
  }
  ll prequeryl (pii ok) {
    if (ok.fi > ok.se) return 0;
    q_query = -infl;
    queryl (1, {1, maxn+1}, {ok.fi+1, ok.se+1});
    return q_query;
  }
};

sgtreel aint;

int main () {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  int i, j, z;
  for (i = 1; i <= m; i++) cin >> v[i].l >> v[i].r >> v[i].scor;
  for (i = 1; i <= m; i++) u[i] = v[i];
  sort (v+1, v+m+1, [](yes a, yes b){ return a.l < b.l; });
  sort (u+1, u+m+1, [](yes a, yes b){ return a.r < b.r; });
  int st = 1, dr = 1;
  fill(all(d), -infl); d[0] = 0;
  for (z = 1; z <= n; z++) {
    while (dr <= m && v[dr].l == z) {
      aint.preupdatel({0,v[dr].l-1}, v[dr].scor);
      dr++;
    }
    d[z] = aint.prequeryl({0, z-1});
    aint.preupdatel({z,z}, d[z]);
    while (st <= m && u[st].r == z) {
      aint.preupdatel({0,u[st].l-1}, -u[st].scor);
      st++;
    }
  }
  cout << (*max_element(all(d)));
  return 0;
}
