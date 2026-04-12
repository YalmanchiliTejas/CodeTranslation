#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void){
  int n;

  while(cin >> n){
	if(n == 0) break;
	int field[n][n];
	int x= n/2 + 1;
	int y= n/2;
	int i=2;

	memset(field, -1, sizeof(field));
	field[x][y] = 1;
	x++; y++;
	while(i <= n*n){
	  if(x == n) x = 0;
	  if(y == n) y = 0;
	  if(x == -1) x = n-1;
	  if(y == -1) y = n-1;

	  if(field[x][y] == -1){
		field[x][y] = i++;
		x++; y++;
	  }else{
		x++; y--;
	  }
	}

	for(int i=0;i<n;i++){
	  for(int j=0;j<n;j++){
		printf("%4d", field[i][j]);
	  }
	  cout << endl;
	}
  }
  return 0;
}