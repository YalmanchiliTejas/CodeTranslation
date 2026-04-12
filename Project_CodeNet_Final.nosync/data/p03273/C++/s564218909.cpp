#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
char map[505][505];
bool banx[505]= {false};
bool bany[505]= {false};
int n,m;
bool flag;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int r=1; r<=m; r++)
			cin>>map[i][r];
	flag=false;
	for(int i=1; i<=n; i++) {
		flag=false;
		for(int r=1; r<=m; r++)if(map[i][r]=='#')flag=true;
		if(!flag)banx[i]=true;
		}
	for(int i=1; i<=m; i++) {
		flag=false;
		for(int r=1; r<=n; r++)if(map[r][i]=='#')flag=true;
		if(!flag)bany[i]=true;
		}
	for(int i=1; i<=n; i++) {
		for(int r=1; r<=m; r++)
			if((!banx[i])&&(!bany[r]))cout<<map[i][r];
		if(!banx[i])cout<<endl;
		}
	}

