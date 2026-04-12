#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int num[17][17];
  int n;

  while(1){
    int count=1;
    cin>>n;
    if(n==0)break;

    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
	num[i][j]=0;
      }
    }
    
    int dx,dy;
    dx=(n+1)/2;
    dy=(n+1)/2-1;

    while(1){
      if(count>n*n)break;
      if(dx>=n)dx=0;
      else if(dy>=n)dy=0;
      else if(dy<0)dy=n-1;
      else if(num[dx][dy]==0){
	num[dx][dy]=count;
	count++;
	dx+=1;
	dy+=1;
      }else if(num[dx][dy]!=0){
	dx+=1;
	dy-=1;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	printf("%4d",num[i][j]);
      }
      cout<<endl;
    }
  }
  
  return 0;
}