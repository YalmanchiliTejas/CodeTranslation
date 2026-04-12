#include<bits/stdc++.h>
using namespace std;

int main(){
  while(1){
  int n;
  cin>>n;
  if(n==0) break;
  int m[20][20]={};
  int na=(n*n)/2;
  int dx=n/2,dy=n/2+1;
  m[dy][dx]=1;
     int cnt=1;
    int nx=dx+1,ny=dy+1;
    int t=1;
  while(1){
      if(cnt==n*n) break;
      if(ny>=n){ny=0;continue;}//sita
      else if(nx>=n){nx=0;continue;}//migi
      else if(nx<0){nx=n-1;continue;}//hidari
      else if(m[ny][nx]>0){nx--,ny++;continue;}//aru
     else{cnt++;m[ny][nx]=cnt;nx++;ny++;}
  }
      
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) printf("%4d",m[i][j]);
  cout<<endl;
  }
  }
    
    
  return 0;
}