#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <map>
#include <queue>
#include <string>
using namespace std;

int n,f[15][15];

int main(){
	while(cin>>n){
		if(n==0)return 0;
		for(int i=0;i<15;i++)for(int j=0;j<15;j++)f[i][j]=0;
		int x=n/2,y=n/2+1;
		f[y][x]=1;
		for(int i=2;i<=n*n;i++){
			x++;y++;x%=n;y%=n;
			if(f[y][x]!=0){x--;y++;x=(x+n)%n;y%=n;}
			f[y][x]=i;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<" ";
				if(f[i][j]<100)cout<<" ";
				if(f[i][j]<10)cout<<" ";
				cout<<f[i][j];
			}
			cout<<endl;
		}
	}
}