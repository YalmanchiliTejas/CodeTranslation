#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
	int H,W;
	cin >> H >> W;
	char a[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> a[i][j];
		}
	}
	
	for(int i=0;i<H;i++){
		int count=0;
		for(int j=0;j<W;j++){
			if(a[i][j]=='.') count++;
		}
		if(count==W){
			for(int j=0;j<W;j++) a[i][j]='x';
		}
	}
	for(int j=0;j<W;j++){
		int count=0;
		for(int i=0;i<H;i++){
			if(a[i][j]=='.'||a[i][j]=='x') count++;
			if(count==H){
				for(int i=0;i<H;i++) a[i][j]='x';
			}
		}
	}
	
	for(int i=0;i<H;i++){
		int count=0;
		for(int j=0;j<W;j++){
			if(a[i][j]!='x'){
				cout << a[i][j];
				count++;
			}
		}
		if(count!=0) cout << endl; 
	}
}