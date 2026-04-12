#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
#define LL long long
#define maxn 110
#define inf 0x3f3f3f3f

int G[maxn][maxn];
int n,m;
char c;
int low[maxn],col[maxn];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf(" %c",&c);
			G[i][j]=(c=='#');
			low[i]+=G[i][j];
			col[j]+=G[i][j];
		}
	for(int i=1;i<=n;i++){
		if(low[i]==0) continue;
		for(int j=1;j<=m;j++)
			if(col[j]==0) continue;
			else printf("%c",G[i][j]==1?'#':'.');
		puts("");
	}

	return 0;
}
