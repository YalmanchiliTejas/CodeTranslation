#include<bits/stdc++.h>
using namespace std;
int a[20][20],n;
bool ch(int b){
  return 0<=b&&b<n;
}
int main(){
  while(cin>>n,n){
    memset(a,0,sizeof(a));
    int t=0,x=n/2,y=n/2+1;
    while(t!=n*n){
      if(ch(y)&&ch(x)&&!a[y][x])a[y++][x++]=++t;
      else 
	{
	  if(ch(y)&&ch(x))x--,y++;
	  else{
	    if(y==n)y=0;
	    if(y==-1)y=n-1;
	    if(x==n)x=0;
	    if(x==-1)x=n-1;
	  }
	}
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
	printf("%4d",a[i][j]);
      cout<<endl;
    }
  }
  return 0;
}