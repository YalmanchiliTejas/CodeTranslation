#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int i,j,k;
  while(cin>>n,n){
    int mat[n][n];
    fill(mat[0],mat[n],-1);
    int x=n/2,y=n/2+1;
    for(i=1;i<=n*n;i++){
      //ut << x << y << endl;
      mat[y][x]=i;
      x++;y++;
      if(x>=n){
	x=0;
      }
      if(y>=n){
	y=0;
      }
      if(i==n*n) break;
      while(mat[y][x]!=-1){
	x--;
	y++;
	if(x<0){
	  x=n-1;
	}
	if(y>=n){
	  y=0;
	}
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	printf("%4d" ,mat[i][j]); 
      }
      cout << endl;
    }
  }
  return 0;
}