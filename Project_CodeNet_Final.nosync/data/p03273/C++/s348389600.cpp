#include <bits/stdc++.h>
using namespace std;
#define int long long int
char grid[105][105];
int r[105];
int c[105];
int32_t main(){
	int h,w;cin>>h>>w;
	for(int i=1;i<=h;i++){
		cin>>grid[i]+1;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(grid[i][j]=='#'){
				r[i]=1;
				c[j]=1;
			}
		}
	}
	for(int i=1;i<=h;i++){
		if(r[i]){
			for(int j=1;j<=w;j++){
				if(c[j]) cout<<grid[i][j];
			}
			cout<<"\n";
		}
	}
}
