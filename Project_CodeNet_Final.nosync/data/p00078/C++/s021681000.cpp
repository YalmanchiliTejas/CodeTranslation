#include<bits/stdc++.h>
#define N 15
using namespace std;
int n,ans[N][N],cnt,num;

int main(){
  while(1){
    cnt=1,num=2;
    memset(ans,0,sizeof(ans));
    cin>>n;
    if(!n)break;
    int y=n/2+1,x=n/2;
    ans[y][x]=1;
    while(cnt++!=n*n){
      y++,x++;
      if(n<=y)y=0;
      if(n<=x)x=0;
      while(ans[y][x]){
	y++,x--;
	if(n<=y)y=0;
	if(n<=x)x=0;
	if(y<0)y=n-1;
	if(x<0)x=n-1;
      }
      ans[y][x]=num++;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
	printf("%4d",ans[i][j]);
      cout<<endl;
    }
  }
  return 0;
}