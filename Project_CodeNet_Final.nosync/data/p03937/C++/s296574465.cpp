#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int h,w;
int boomsum = 0;
vector<vector<char>> maze(10,vector<char>(10,'.'));

int dfs(int a,int b){
  if(a<1 || h<a) return 0;
  if(b<1 || w<b) return 0;
  if(maze[a][b] == '.') return 0;
  if(a==h && b==w) return 1;
  return 1 + max(dfs(a+1,b),dfs(a,b+1));
}

int main(){
  cin >> h >> w;
  int check = 0;
  rep1(i,h) rep1(j,w){
    cin >> maze[i][j];
    check += (maze[i][j]=='#');
  }
  if(dfs(1,1) == check) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}