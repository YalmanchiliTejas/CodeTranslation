#include <iostream>
using namespace	std;
int n,g[8][8],r,flag[8];
void check(int now,int how){

  how++;
  flag[now]=1;
  if(how==n) r++;
  for(int i=0;i<n;i++) if(g[now][i]&&flag[i]!=1) check(i,how);
  flag[now]=0;
}
int main(){

  int m,a,b,flag[8]={};

  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    g[a-1][b-1]=1;
    g[b-1][a-1]=1;
  }

  check(0,0);
  cout<<r<<endl;

  return 0;

}
