#include<bits/stdc++.h>
using namespace std;

int main(){

  int n;

  int a[15][15];
  int num;
  int ok;
  int x,y;

  while(cin>>n , n){
    num = 1; ok=n*n; x=y=n/2; y++;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)a[i][j]=0;

    while(ok>0){
      if(a[y][x]==0){
	a[y][x]=num;
	num++;
	ok--;
      }
      else{
	x-=2;
      }
      y++;x++;
      if(x<0){x = n-1;}
      y%=n; x%=n; 
    }
    
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)
	printf("%4d",a[i][j]);
      cout << endl;
    }
	

  }

  return 0;
}