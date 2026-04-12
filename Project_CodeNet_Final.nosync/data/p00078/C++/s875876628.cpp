#include <bits/stdc++.h>
using namespace std;
int n,mp[16][16];

void saiki(int x,int y,int num){
  if(num>n*n)return;

  if(y>=n)saiki(x,0,num);
  else if(x<0) saiki(n-1,y,num);
  else if(x>=n)saiki(0,y,num);
  else if(mp[y][x]!=0)saiki(x-1,y+1,num); 
  else mp[y][x]=num,saiki(x+1,y+1,num+1);
}

int main(){
  while(cin>>n,n){
    memset(mp,0,sizeof(mp));
    saiki(n/2,n/2+1,1);

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)printf("%4d",mp[i][j]);
      cout <<endl;
    }
  }
  return 0;
}