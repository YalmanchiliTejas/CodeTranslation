#include <cstdio>
#include <iostream>

using namespace std;

char e[102][102];
bool vis1[102],vis2[102];
int n,m;

int main() {
	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>e[i][j];
			if(e[i][j]=='#') vis1[i]=1,vis2[j]=1;
		}
	}
	
	int ok=0;
	for(int i=1;i<=n;i++) {
		ok=0;
		for(int j=1;j<=m;j++) {
			if(vis1[i]&&vis2[j]) printf("%c",e[i][j]),ok=1;
		}if(ok) printf("\n");
	}
	
	return 0;
}