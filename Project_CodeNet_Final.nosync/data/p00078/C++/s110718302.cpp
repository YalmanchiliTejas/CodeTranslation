#include <bits/stdc++.h>
using namespace std;


int main(){
  int n,a[20][20];
  while(cin>>n, n){
    memset(a,0,sizeof(a));
    int x=n/2,y=n/2+1;
    for(int i=1;i<n*n;i++){
      a[y][x]=i;
      x=(x+1)%n;
      y=(y+1)%n;
      while(a[y][x]!=0){x=(x+n-1)%n;y=(y+1)%n;}
    }
    a[y][x]=n*n;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++) printf("%4d",a[i][j]);
      cout<<endl;
    }
  }

  return 0;
}