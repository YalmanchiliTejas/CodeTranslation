#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  int n;
  int table[20][20];

  while(cin >> n,n){
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)table[i][j] = 0;

    int y = n/2+1, x = n/2;

    for(int i=1;i<=n*n;i++){
      table[y][x] = i;
      y++; x++;

      while(true){
	if(i==n*n)break;

	if(y>=n)y=0;
	if(x<0)x=n-1;
	if(x>=n)x=0;
	
	if(table[y][x]){
	  y++; x--;
	}else{
	  break;
	}
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cout << setw(4) << right << table[i][j];
      }
      cout << endl;
    }
  }
}
	