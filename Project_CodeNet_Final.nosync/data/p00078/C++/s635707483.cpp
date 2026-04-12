#include <bits/stdc++.h>
#define range(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) range(i,0,n)
using namespace std;

int table[15][15];

int main(void){
	int n;
	while(cin >> n,n){
		rep(i,n)rep(j,n) table[i][j]=-1;

		int ci=n/2+1,cj=n/2;
		int num=1;
		while(num<=n*n){
			if(table[ci][cj]!=-1){
				ci=(ci+1)%n;
				cj=(cj+n-1)%n;
			}
			table[ci][cj]=num++;
			ci=(ci+1)%n;
			cj=(cj+1)%n;
		}
		rep(i,n){
			rep(j,n) printf("%4d",table[i][j]);
			puts("");
		}
	}
	return 0;
}