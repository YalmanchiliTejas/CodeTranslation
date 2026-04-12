#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<string>
#include<cmath>
#include<tuple>
#define INF 1111111
using namespace std;
typedef pair<int,int> P;
typedef tuple<int,int,int> tup;
typedef long long ll;

int dy[4]={-1, 0, 1, 0};
int dx[4]={0, -1, 0, 1};
queue<tup> q; 

int sides[10][10];
int a,b;
int n,m;
int ans;

void dfs(int start, int passed[10]){
  int nowpas[10];
  for(int i=0;i<=10;i++)
    nowpas[i] = passed[i];
  for(int i=1;i<=n;i++)
  nowpas[start] = 1; 
  bool flag = true;
  for(int j=1;j<=n;j++){
    if(nowpas[j] == 0)
       flag = false;
  }
  if(flag){
     ans++;
     
  }
  for(int i=1;i<=n;i++){
    if(sides[start][i] == 1 && nowpas[i] == 0){
      dfs(i,nowpas);
    }
  }
}


int main(){
  
  cin >> n >> m;
  int passed[10] = {};
  
  
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      sides[i][j] = 0;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    sides[a][b] = 1;
    sides[b][a] = 1;
  }
  ans = 0;
  int start = 1;
  passed[start] = 1;
  dfs(start, passed);
  
  cout << ans << endl;
  
}