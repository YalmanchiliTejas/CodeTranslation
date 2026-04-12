#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int t[15][15];

void rec(int y,int x,int cnt){

  t[y][x]=cnt;
    if(cnt==n*n)return;
  /*
  cout<<y<<" "<<x<<endl;
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cout<<t[i][j]<<" ";
      }
      cout<<endl;
    }
  */


  int ny=(y+1)%n,nx=(x+1)%n;
  while(t[ny][nx]!=0){
    ny++;
    nx--;
    if(ny==n){
      ny=0;
    }
    if(nx<0){
      nx+=n;
    }
  }
  rec(ny,nx,cnt+1);
}
int main(){
  while(cin>>n){
    if(n==0)break;

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
	t[i][j]=0;
    
    rec(n/2+1,n/2,1);

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	//cout<<t[i][j]<<" ";
	//if(j)cout<<' ';
	printf("%4d",t[i][j]);

      }
      cout<<endl;
    }
  }
  return 0;
}