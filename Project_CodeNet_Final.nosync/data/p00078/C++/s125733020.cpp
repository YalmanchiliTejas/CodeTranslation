//Magic Square
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin>>n){
    int cn=1;
    if(n==0)break;
    int a[n][n];
    int x=n/2+1, y=n/2;
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        a[i][j]=0;
    a[x][y]=1;
    while(cn!=n*n){
      x=(x+1)%n; y=(y+1)%n;
      if(a[x][y]!=0){
        x=(x+1)%n; y=(y-1)%n;
        if(x<0)x+=n;
        if(y<0)y+=n;
      }
      a[x][y]=cn+1;
      cn++;
    }
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        if(j==n-1)printf("%4d\n", a[i][j]);
        else printf("%4d", a[i][j]);
  }
  return 0;
}