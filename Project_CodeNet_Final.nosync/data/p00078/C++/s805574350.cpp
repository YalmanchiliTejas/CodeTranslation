#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int a[15][15];
  int n,x,y,i=1;

  cin >>n;

  while (n!=0){
    for (int j=0;j<n*n;j++)a[j/n][j%n]=-1;
    
    x=n/2;
    y=n/2+1;
    i=1;
    while(i<=n*n){
      if (x>=n){
	x=0;
	continue;
      }else if (x<0){
	x=n-1;
	continue;
      }else if (y>=n){
	y=0;
	continue;
      }else if (y<0){
	y=n-1;
	continue;
      }
      //      cout << i<<"("<<x<<","<<y<<")";
      if (a[y][x]==-1){
	//	cout <<"-";
	a[y][x]=i;
	x++;
	y++;
	i++;
      }else{
	//	cout <<"*("<<a[y][x]<<")**";
	x--;
	y++;
      }
    }

    for (y=0;y<n;y++){
      for (x=0;x<n;x++)
	printf("%4d", a[y][x]);
      cout << endl;
    }
    cin >> n;
  }
  return 0;
}
  