#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> PP;
static const int INF = 1000010000;
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue
 
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge{
  int to;
};

int main(){
  int n, m;
  cin >> n >> m;
  bool flag[10][10];
  REP(i, 10) REP(j, 10){
    flag[i][j] = false;
  }
  REP(i, m){
    int a, b;
    cin >> a >> b;
    flag[a][b] = flag[b][a] = true;
  }
  int ans = 0;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
  do {
    if(v[0] != 1) continue;
    int s = v[0];
    bool f = true;
    REP(i, n - 1){
      if(!flag[v[i]][v[i + 1]]){
        f = false;
      }
    }
    if(f) ans++;
  }while(next_permutation(v.begin(), v.end()));
  cout << ans << endl;
}

