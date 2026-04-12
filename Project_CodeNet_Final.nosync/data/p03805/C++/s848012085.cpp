#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <iomanip>
#include <stack>
#include <queue>
#include <algorithm>

#define REP(i, n) for(int i = 0;i < n;i++)

using namespace std;

const int INF = 100000000;
int edge[30][2];

bool check(int m,int begin,int end){

  REP(i,m){
    if ((edge[i][0] == begin && edge[i][1] == end) || (edge[i][1] == begin && edge[i][0] == end)) {
      return true;
    }
  }
  return false;

}

int solve(int n,int m){
  vector<int> node(n);
  REP(i,n){
    node[i] = i + 1;
  }

  int ans = 0;

  do {
    if (node[0] != 1) {
      continue;
    }
    REP(j,n){
      if (j == n-1) {
        ans++;
      }
      if (check(m,node[j],node[j+1]) == false) {
        break;
      }
    }
  } while (next_permutation(node.begin(),node.end()));
  return ans;
}

int main(){
  int n,m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> edge[i][0] >> edge[i][1];
  }

  int ans = solve(n,m);
  cout << ans << endl;

  return 0;
}