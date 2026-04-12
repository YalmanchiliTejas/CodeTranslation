#include <iostream>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int n, m;
int map[10][10];
bool visit[10];
int ans = 0;

bool all_visited()
{
  REP(i, n) {
    // 見てないところがあったら　false
    if(! visit[i]) return false;
  }
  return true;
}

void dfs(const int pos)
{
  visit[pos] = true;
  if(all_visited()) {
    ans++;
    visit[pos] = false;
    return;
  }
  REP(i, n) {
    if(map[pos][i]) {
      if(! visit[i]) {
        dfs(i);
      }
    }
  }
  visit[pos] = false;
  return;
}

int main()
{
  cin >> n >> m;
  REP(i, 10)
    REP(k, 10)
      map[i][k] = 0;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    map[a][b] = 1;
    map[b][a] = 1;
  }
  dfs(0);
  cout << ans << endl;
}
