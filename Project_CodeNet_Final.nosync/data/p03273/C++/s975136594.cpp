#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
using namespace std;
int n,m;
char s[101][101];
bool tf[101][101],k;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf(" %c",&s[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		k=true;
		for(int j=1;j<=m;j++) if(s[i][j]!='.') k=false;
		if(k){
			for(int j=1;j<=m;j++) tf[i][j]=true;
		}
	}
	for(int i=1;i<=m;i++){
		k=true;
		for(int j=1;j<=n;j++) if(s[j][i]!='.') k=false;
		if(k){
			for(int j=1;j<=n;j++) tf[j][i]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(!tf[i][j]) printf("%c",s[i][j]);
		k=true;
		for(int j=1;j<=m;j++) if(!tf[i][j]) k=false;
		if(!k) printf("\n");
	}
	return 0;
} 