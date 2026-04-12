#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int N;
int H[16], W[16];
char C[4][4];
int c[4][4];

string clr = "RGB";

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N;
  rep(i, N) cin >> H[i] >> W[i];

  rep(i, 4) rep(j, 4) cin >> C[i][j], c[i][j] = clr.find(C[i][j]);

  int d[1<<16];
  memset(d, -1, sizeof(d));
  d[0] = 0;
  queue<int> que;
  que.push(0);
  while(!que.empty()) {
    int bit = que.front(); que.pop();
    if(bit == (1<<16)-1) break;
    rep(i, 3) rep(j, N) {
      reps(k, -H[j]+1, 4) reps(l, -W[j]+1, 4) {
	int nbit = bit;
	reps(y, max(k, 0LL), min(k+H[j], 4LL)) {
	  reps(x, max(l, 0LL), min(l+W[j], 4LL)) {
	    int mask = 1<<(y*4+x);
	    if(c[y][x] == i && !((bit >> (y*4+x)) & 1) ||
	       c[y][x] != i && (bit >> (y*4+x)) & 1) {
	      nbit ^= mask;
	    }
	  }
	}
	if(d[nbit] == -1) {
	  d[nbit] = d[bit] + 1;
	  que.push(nbit);
	}
      }
    }
  }

  cout << d[(1<<16)-1] << endl;

  return 0;
}