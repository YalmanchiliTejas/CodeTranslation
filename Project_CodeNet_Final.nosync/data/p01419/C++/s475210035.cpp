#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mp make_pair

const int MAXN = 55;
int R, C;
char mat[MAXN][MAXN];
int viz[MAXN][MAXN];
int powerPerTime[MAXN][MAXN];
int turnOn[MAXN][MAXN];
int turnOff[MAXN][MAXN];
vector<int> times[MAXN][MAXN];

void readMat(int k[MAXN][MAXN]) {
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
      scanf("%d", &k[i][j]);
}

int d[] = { 0, 1, 0, -1, 1, 0, -1, 0 };

LL solveFor(int i, int j) {
  vector<int> &v = times[i][j];
  if (v.size() == 0)
    return 0;
  LL ans = turnOn[i][j];
  for (int k = 0; k < (int)v.size() - 1; ++k) {
    int timeSpent = v[k + 1] - v[k];
    LL costStingAprind = turnOff[i][j] + turnOn[i][j];
    LL costLasLumina = 1LL * timeSpent * powerPerTime[i][j];
    ans += min(costLasLumina, costStingAprind);
  }
  ans += turnOff[i][j];
  return ans;
}

vector< pair< int, pair<int, int> > > DFSrez;
int tari, tarj;
int dfsmark;

bool DFSsol(int curi, int curj, int lvl) {
  viz[curi][curj] = dfsmark;
  if (curi == tari && curj == tarj)
    return true;
  for (int di = 0; di < 4; ++di) {
    int ni = curi + d[di * 2], nj = curj + d[di * 2 + 1];
    if (ni < 0 || nj < 0 || ni >= R || nj >= C)
      continue;
    if (mat[ni][nj] == '#')
      continue;
    if (viz[ni][nj] == dfsmark)
      continue;
    if (!DFSsol(ni, nj, lvl + 1))
      continue;
    DFSrez.push_back(mp(lvl + 1, mp(ni, nj)));
    return true;
  }
  return false;
}

int main() {
  int M;
  scanf("%d%d%d", &R, &C, &M);
  memset(viz, 0xFF, sizeof viz);
  for(int i=0; i<R; ++i)
    for (int j = 0; j < C; ++j) {
      scanf(" %c", &mat[i][j]);
      if (mat[i][j] == '#')
        continue;
    }
  readMat(powerPerTime);
  readMat(turnOn);
  readMat(turnOff);
  int curi, curj;
  scanf("%d%d", &curi, &curj);
  int curTime = 0;
  times[curi][curj].push_back(0);
  for (dfsmark = 0; dfsmark < M - 1; ++dfsmark) {
    scanf("%d%d", &tari, &tarj);
    DFSrez.clear();
    assert(DFSsol(curi, curj, curTime));
    for (int itt = 0; itt < (int)DFSrez.size(); ++itt) {
      auto &it = DFSrez[itt];
      times[it.second.first][it.second.second].push_back(it.first);
    }
    curTime = DFSrez[0].first;
    curi = tari, curj = tarj;
  }
  LL ans = 0;
  for(int i=0; i<R; ++i)
    for(int j=0; j<C; ++j)
      ans += solveFor(i, j);
  printf("%lld\n", ans);
  return 0;
}

