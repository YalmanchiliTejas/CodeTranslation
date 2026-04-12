#include <iostream>
using namespace std;
char c[10][10];
bool m[10][10];
bool dfs(int a,int b,int h,int w){
  m[a][b]=true;
  if(a==h-1&&b==w-1){
    bool flag = true;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++) 
        if(c[i][j]=='#'&&!m[i][j]){flag=false; break;}
    if(flag) return true;
    else return false;
  }
  if(a<h-1&&c[a+1][b]=='#'){
    if(dfs(a+1,b,h,w)) return true;
  }
  if(b<w-1&&c[a][b+1]=='#'){
    if(dfs(a,b+1,h,w)) return true;
  }
  m[a][b]=false;
  return false;
}

int main(){
  int h,w;
  cin >> h >> w;
  for(int i=0;i<h;i++) cin >> c[i];
  for(int i=0;i<10;i++) for(int j=0;j<10;j++) m[i][j] = false;
  if(dfs(0,0,h,w)) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}
    