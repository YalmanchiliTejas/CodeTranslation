#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){

  int n;
  int a[100][100];
  int i = 1;
  int x,y;

  while(cin >> n, n){

    memset(a,0,sizeof(a));
    i = 1;

    x = n/2+1;
    y = n/2;

    a[x][y] = i;

    x++;
    y++;
    i++;

    while(true){

      int k = 0;

      if(x < n && y < n && x >= 0 && y >= 0 && !a[x][y]){
	  a[x][y] = i;
	  k = 1;
	}

	else if(x >= n) x = 0;
	else if(y >= n) y = 0;
	else if(y < 0) y = n-1; 
	else if(x < n && y < n && a[x][y] != 0){
	  x++;
	  y--;
	}

	if(!k) continue;

	i++;
	x++;
	y++;

	if(i == n*n+1) break;

	}

      for(int i=0;i<n;i++){
	for(int j=0;j<n;j++) printf("%4d",a[i][j]);
	cout << endl; 
      }

    }
  }