#include<iostream>
using namespace std;

const int MAX_N = 15;

int main(){
  int n;
  int a[MAX_N][MAX_N];

  while(cin >> n){
    if(n==0) break;

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
	a[i][j]=0;
    
    int x=n/2+1, y=n/2;
    a[x][y]=1;
    for(int i=2; i<=n*n; i++){
      x++; y++;
      while(1){
	if(y>n-1) y=0;
	if(y<0) y=n-1;
	if(x>n-1) x=0;
	if(a[x][y]==0) break;
	x++; y--;
      }
      a[x][y] = i;
      //      cout << a[x][y] << endl;
    }
    
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	printf("%4d",a[i][j]);
      }
      cout << endl;
    }
  }

}