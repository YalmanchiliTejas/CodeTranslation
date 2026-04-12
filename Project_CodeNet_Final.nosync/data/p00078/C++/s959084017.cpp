#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int n;
  while(cin >>n,n){
    int m[15][15]={0};
    int x=n/2,y=n/2+1;
    for(int i=1; i<=n*n; i++){
      m[x][y] = i;
      x++;
      y++;
      x%=n;
      y%=n;
      if(m[x][y]!=0){x+=n-1;y++;x%=n;y%=n;}
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	printf("%4d",m[j][i]);
      }
      cout <<endl;
    }
  }
  return 0;
}