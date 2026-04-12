#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int n,i,j,x,y,mh[15][15];
	while(cin >> n) {
		if (n==0) break;
		memset(mh,0,sizeof(mh));
		x=n/2; y=n/2+1; 
		for (i=1;i<=n*n;i++) {
			while(true) {
				if (mh[y][x]==0) { mh[y][x]=i; break;}
				else { x=(x+(n-1)) % n; y=(y+1) % n; }
			}
				x=(x+1) % n;
				y=(y+1) % n;
		}
		for (i=0;i<n;i++) {
			for (j=0;j<n;j++) printf("%4d",mh[i][j]);
			cout << endl;
		}
	}
   
	return 0;
}