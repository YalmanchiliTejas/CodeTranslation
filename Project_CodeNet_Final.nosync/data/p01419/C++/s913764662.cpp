#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int R, C, M;
char room[55][55];
int cost[3][55][55];
int rs[1001], cs[1001];

int d[55][55];
int pv[55][55];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> R >> C >> M;
  rep(i, R) rep(j, C) cin >> room[i][j];
  rep(i, 3) rep(j, R) rep(k, C) cin >> cost[i][j][k];
  rep(i, M) cin >> rs[i] >> cs[i];

  vector< tuple<int, int, int> > vec;
  vec.emplace_back(rs[0], cs[0], 0);
  int st = 0;
  rep(i, M-1) {
    memset(d, -1, sizeof(d));
    memset(pv, -1, sizeof(pv));
    d[rs[i]][cs[i]] = st;
    pv[rs[i]][cs[i]] = 4;
    queue< pair<int, int> > que;
    que.emplace(rs[i], cs[i]);
    while(!que.empty()) {
      int r, c;
      tie(r, c) = que.front(); que.pop();
      if(r == rs[i+1] && c == cs[i+1]) {
	st = d[r][c];
	break;
      }
      rep(j, 4) {
	int nr = r + dr[j], nc = c + dc[j];
	if(nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
	if(room[nr][nc] == '#' || d[nr][nc] != -1) continue;
	d[nr][nc] = d[r][c] + 1;
	pv[nr][nc] = j;
	que.emplace(nr, nc);
      }
    }
    vector< tuple<int, int, int> > tmp;
    int r = rs[i+1], c = cs[i+1];
    while(r != rs[i] || c != cs[i]) {
      tmp.emplace_back(r, c, d[r][c]);
      int nr = r - dr[pv[r][c]], nc = c - dc[pv[r][c]];
      r = nr, c = nc;
    }
    reverse(all(tmp));
    rep(j, tmp.size()) vec.emplace_back(tmp[j]);
  }

  int ans = 0;
  int used[R][C];
  memset(used, -1, sizeof(used));
  for(auto v : vec) {
    int r, c, e;
    tie(r, c, e) = v;
    //cout << r << " " << c << " " << e << endl;
    if(~used[r][c]) {
      ans += min((e - used[r][c]) * cost[0][r][c], cost[2][r][c] + cost[1][r][c]);
    } else {
      ans += cost[1][r][c] + cost[2][r][c];
    }
    used[r][c] = e;
  }
  cout << ans << endl;

  return 0;
}