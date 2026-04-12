#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define EPS 1e-10
#define INF 1000000
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef pair<int,int> pii;
typedef long long ll;

ll addSum( vbb T, vb visited, int pos ) {
  int len = T.size();
  bool visited_all = true;

  for (int i = 0; i < len; i++) {
    if (!visited[i]) {
      visited_all = false;
    }
  }
  if (visited_all) {
    return 1;
  }

  ll ans = 0;
  for (int i = 0; i < len; i++) {
    if (!T[pos][i] || pos == i) {
      continue;
    }
    if (visited[i]) {
      continue;
    }

    visited[i] = true;
    ans += addSum(T, visited, i);
    visited[i] = false;
  }

  return ans;
}

ll calc( vbb T ) {
  int len = T.size();
  ll ans = 0;
  vb visited(len, false);

  int st = 0;
  //for (int st = 0; st < len; st++) {
    visited[st] = true;
    ans += addSum(T, visited, 0);
    //visited[st] = false;
  //}

  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;

  if (M == 0) {
    cout << 0 << endl;
    return 0;
  }

  vbb T(N, vb(N, false));
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    T[a-1][b-1] = true;
    T[b-1][a-1] = true;
  }

  ll ans = calc(T);
  cout << ans << endl;
}