#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	char a[h][w];
	char c1[h][w];
	char c2[h][w];
	
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> a[i][j];
			c1[i][j]=a[i][j];
			c2[i][j]=a[i][j];
		}
	}
	
	for(int i=0;i<h;i++){
		bool f=true;
		for(int j=0;j<w;j++){
			if(a[i][j]=='#')f=false;
		}
		if(f==true){
			for(int x=0;x<w;x++){
				c1[i][x]='A';
			}
		}
	}
	
	for(int i=0;i<w;i++){
		bool f=true;
		for(int j=0;j<h;j++){
			if(c2[j][i]=='#')f=false;
		}
		if(f){
			for(int x=0;x<h;x++){
				c2[x][i]='B';
			}
		}
	}
	
	for(int i=0;i<h;i++){
		if(c1[i][0]=='A')continue; 
		for(int j=0;j<w;j++){
			if(c2[i][j]=='B')continue;
			cout << a[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
