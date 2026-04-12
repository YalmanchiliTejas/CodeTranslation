#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int

typedef long long ll;
typedef pair<ll,ll> p;
int h, w;

bool check(vector<string> v)
{
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      // cout << v[i][j];
      if(v[i][j] == '#') return false;
    }
    // cout << endl;
  }
  return true;
}

int main()
{
  cin >> h >> w;
  vector<string> v(h, "@");
  for (int i = 0; i < h; i++) {
    cin >> v[i];
  }
  v[0][0] = '@';
  int dx[2] = {1, 0};
  int dy[2] = {0, 1};

  queue<p> q;
  q.push({0, 0});
  while(q.size() != 0) {
    p tmp = q.front();
    for (int i = 0; i < 2; i++) {
      int ny = tmp.first + dy[i];
      int nx = tmp.second + dx[i];
      if(ny >= 0 && ny < h && nx >= 0 && nx < w && v[ny][nx] == '#')
      {
        q.push({ny, nx});
        v[ny][nx] = '@';
        break;
      }
      else continue;
    }
    q.pop();
  }

  bool flag = check(v);

  if(flag) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
