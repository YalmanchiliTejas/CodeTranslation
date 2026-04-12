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
#define maxn 3000

using namespace std;

ll d[maxn+5][maxn+5][2], v[maxn+5];
bool viz[maxn+5][maxn+5][2];
///d[i][j][0]=diff max dc rezolvam secventa i..j cu Taro la mutare
///d[i][j][1]=diff min i..j Jiro

ll Dp (int l, int r, int wh) {
  if (l > r) return ((wh == 0)? -infl: infl);
  if (viz[l][r][wh]) return d[l][r][wh];
  viz[l][r][wh] = 1;
  if (l == r) d[l][r][wh] = ((wh == 0)? v[l]: -v[l]);
  else {
    if (wh == 0) d[l][r][0] = max(v[l] + Dp(l+1,r,1), v[r] + Dp(l,r-1,1));
    else d[l][r][1] = min(-v[l] + Dp(l+1,r,0), -v[r] + Dp(l,r-1,0));
  }
  return d[l][r][wh];
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int i, j, z;
  for (i = 1; i <= n; i++) cin >> v[i];
  cout << Dp(1,n,0);
  return 0;
}
