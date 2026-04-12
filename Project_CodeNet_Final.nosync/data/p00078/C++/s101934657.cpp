#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	while(1){
		int a[15][15];
		int n; cin >> n ;
		if(!n) break;
		for(int i=0;i<15;i++)
			for(int j=0;j<15;j++) a[i][j]=0;
		int y=n/2+1 ; int x=n/2 ;
		int num=1;
		while(1){
		if(a[y][x]==0) a[y++][x++]=num++;
		else if(a[y][x]!=0) x--,y++;
		if(num>n*n) break;
		if(x>=n) x-=n; if(x<0) x+=n;
		if(y>=n) y-=n; if(y<0) y+=n;
		};
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << setw(4) ;
				cout << a[i][j] ;
			};
			cout << '\n' ;
		};
	};
};