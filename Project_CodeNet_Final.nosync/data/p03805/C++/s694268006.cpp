#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n,m; cin >> n >> m;
  int cost[10][10];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cost[i][j] = -1;
  }
  for(int i=0;i<m;i++){
    int a,b; cin >> a >> b;
    a--; b--;
    cost[a][b] = 1;
    cost[b][a] = 1;
  }

  int P[10];
  for(int i=0;i<n;i++) P[i] = i;

  int ans = 0;
  do{
    if(P[0] != 0) break;
    bool flag = true;
    for(int i=0;i<n-1;i++){
      if(cost[P[i]][P[i+1]] < 0) flag = false;
    }
    if(flag) ans++;
  }while(next_permutation(P,P+n));

  cout << ans << endl;
  return 0;
}