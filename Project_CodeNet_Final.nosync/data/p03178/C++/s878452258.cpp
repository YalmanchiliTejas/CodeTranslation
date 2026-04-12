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

using namespace std;

struct yes { int p1, p2, p3, p4; };

const int mod = 1000000007;
int d[10005][10][100][2];
///d[nr cifre][ult cifra][rest mod k][exista cifra strict mai mica decat cea din n?]

int modk (int a, int b, int k) {
  return (a+b) % k;
}

void mad (int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string n; int k; cin >> n >> k;
  for (char &ch: n) ch -= '0'; ///wow!!
  int i, j, x, y, z, ans = 0;
  d[0][0][0][0] = 1;
  for (i = 0; i < sz(n); i++)
    for (j = 0; j <= 9; j++)
      for (x = 0; x < k; x++) {
        mad(d[i+1][n[i]][modk(x,n[i],k)][0], d[i][j][x][0]);
        for (z = 0; z < n[i]; z++) mad(d[i+1][z][modk(x,z,k)][1], d[i][j][x][0]);
        for (z = 0; z <= 9; z++) mad(d[i+1][z][modk(x,z,k)][1], d[i][j][x][1]);
      }
  for (j = 0; j <= 9; j++) {
    mad(ans, d[sz(n)][j][0][0]);
    mad(ans, d[sz(n)][j][0][1]);
  }
  cout << (ans-1+mod) % mod;///d[0][0][0][0]
  ///exista alt mod?
  return 0;
}
