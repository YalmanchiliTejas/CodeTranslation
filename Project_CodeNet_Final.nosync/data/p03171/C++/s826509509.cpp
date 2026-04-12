#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int nax = 3000;

ll deck[nax];
ll dp[nax][nax];
int indegree[nax][nax];
int n;


void dfs(int a, int b){
  if((n-b+a)%2){
    if(a>0){
      dp[a-1][b] = min(dp[a][b]-deck[a-1],dp[a-1][b]);
      indegree[a-1][b]--;
    }
    if(b<n-1){
      dp[a][b+1] = min(dp[a][b]-deck[b+1],dp[a][b+1]);
      indegree[a][b+1]--;
    }
  }
  else{
    if(a>0){
      dp[a-1][b] = max(dp[a][b]+deck[a-1],dp[a-1][b]);
      indegree[a-1][b]--;
    }
    if(b<n-1){
      dp[a][b+1] = max(dp[a][b]+deck[b+1],dp[a][b+1]);
      indegree[a][b+1]--;
    }
  }
  if(a>0&&indegree[a-1][b]==0){
    dfs(a-1,b);
  }
  if(b<n-1&&indegree[a][b+1]==0){
    dfs(a,b+1);
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> deck[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      indegree[i][j]=2;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i==j)
        dp[i][j]=(n%2==1?1:-1)*deck[i];
      else if((n-1-j+i)%2)
        dp[i][j]=1e14;
      else
        dp[i][j]=-1e14;
    }
  }

  for(int i = 0; i < n; i++){
    dfs(i,i);
  }

  cout << dp[0][n-1] << endl;
  return 0;
}
