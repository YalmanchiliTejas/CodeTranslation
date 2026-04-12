#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[10][10],b[10][10],m[10][10];

void rev(int x,int y) {
	b[y][x]=1;
	if (x>0) a[y][x-1]=1-a[y][x-1];
	if (x<9) a[y][x+1]=1-a[y][x+1];
	if (y>0) a[y-1][x]=1-a[y-1][x];
	if (y<9) a[y+1][x]=1-a[y+1][x];
	a[y][x]=1-a[y][x];
}

int main() {
	int n,i,j,k;
	cin >> n;
	for (n;n>0;n--) {
		for (i=0;i<10;i++) for (j=0;j<10;j++) cin >> m[i][j];
		for (k=0;k<1024;k++) {
			memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
			for (i=0,j=k;i<10;i++,j/=2)  if (j % 2==1) rev(i,0); 
			for (i=1;i<10;i++) for (j=0;j<10;j++) if (m[i-1][j]!=a[i-1][j]) rev(j,i);
			for (i=0;i<10;i++) if (m[9][i]!=a[9][i]) break;
			if (i==10) break; 
		}
		for (i=0;i<10;i++) {
			cout << b[i][0];
			for (j=1;j<10;j++) cout << ' ' << b[i][j];
			cout << endl;
		}
	}
	return 0;
}