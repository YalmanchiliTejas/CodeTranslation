#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

#define MAX_V 1000000

#define MAX_N 10
int n, m;
int a, b;
int maze[MAX_N][MAX_N];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

  cin >> n >> m;
  rep(i, 0, m) {
    cin >> a >> b;
    a--; b--;
    maze[a][b] = 1;
    maze[b][a] = 1;
  }

  int array[n];
  rep(i, 0, n) array[i] = i;

  int rsl = 0;
  do {
    if(array[0] != 0) continue;

    bool isClear = true;
    rep(i, 0, n - 1) {
      if(maze[array[i]][array[i + 1]] == 0) {
        isClear = false;
        break;
      }
    }
    if(isClear) ++rsl;
  } while(next_permutation(array, array + n));

  cout << rsl << endl;
}
