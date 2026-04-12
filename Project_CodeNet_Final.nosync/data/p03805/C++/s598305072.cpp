#include<bits/stdc++.h>
using namespace std;
int co;
int n,m;
int x[8][8];
int bend;
void dfs(int a,int b){
  /*/
  for(int i=0;i<n;i++){
    if(1<<i&b)cout << 1;
    else cout << 0;
  }
  cout << endl;
  /*/
  if(b==bend){
    co++;
    return;
  }
  /*/
  cout << a+1 << endl;
  /*/
  for(int i=0;i<n;i++){
    if(x[a][i]){
      if(1<<i&b)continue;
      b+=1<<i;
      dfs(i,b);
      b-=1<<i;
    }
  }
}
int main(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    bend+=1<<i;
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    x[a][b]=1;
    x[b][a]=1;
  }
  dfs(0,1);
  cout << co << endl;
}