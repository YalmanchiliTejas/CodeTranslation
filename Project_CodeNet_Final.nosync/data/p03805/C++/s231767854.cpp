#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define REP(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define fst first
#define snd second
#define MP make_pair //incase c++11 or later is not available

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;
#define PI = 3.14159265358979323846
/*------------------------------------------------------------------------------*/

int count_DFS(const vector<vector<int>>& G, int index, int cnt, VI& used, int num){
  int ans = 0;

  used[index] = 1;

  cnt++;
  if(cnt == num){
    ans++;
  } else {
    REP(i, 1, (int)G[index].size()+1){
      if(G[index][i] == 1 && !used[i]){
        ans += count_DFS(G, i, cnt, used, num);
      }
    }
  }
  used[index] = 0;

  return ans;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N+1, vector<int>(N+1,0));

  REP(i, 0, M){
    int a, b;
    cin >> a >> b;
    G[a][b] = 1;
    G[b][a] = 1;
  }

  VI used(N+1, 0);
  cout << count_DFS(G, 1, 0, used, N) << endl;

  return 0;
}
