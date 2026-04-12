#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <cmath>
#include <utility> // pair make_pair
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits> // LLONG_MAX, LLONG_MIN, INT_MIN, INT_MAX
#include <assert.h>

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define chmin(x, y) x = min(x, y)
#define ll long long
#define ld long double
//#define int ll
#define INF INT_MAX/10
#define MOD 1000000007

using namespace std;
using Pi = pair<int, int>;
using Graph = vector<vector<int> >;
using WeightGraph = vector<vector<Pi> >;

int Input[100100];


const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<string> field;

/* if bfs

   queue<pair<int, int> > que
   que.push(start x, start y);

   int dist[x][y];
   memset(dist, -1, sizeof(dist));
   dist[start x][start y] = 0;
*/


// int N; cin >> N;
// field.resize(N);
int main() {
  int N, M; cin >> N >> M;
  rep(i, N) {
    string S; cin >> S;
    field.push_back(S);
  }
  set<int> Row, Column;
  rep(i, N) {
    rep(j, M) {
      if (field[i][j] == '#') {
        Row.insert(i);
        Column.insert(j);
      }
    }
  }
  
  rep(i, N) {
    int flag = 0;
    rep(j, M) {
      if (Row.count(i) && Column.count(j)) {
        cout << field[i][j];
        flag = 1;
      }
    }
    if (flag) cout << endl;
  }
}
