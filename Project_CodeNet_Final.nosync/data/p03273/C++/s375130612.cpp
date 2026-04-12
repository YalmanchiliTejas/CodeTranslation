#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1010;
int n,m,i,j,k,a[N][N];
bool b[N][N];
char ch[N];
bool f(int k){
	for (int i=1;i<=m;i++) if (a[k][i]) return false;return true;
}
bool ff(int k){
	for (int i=1;i<=n;i++) if (a[i][k]) return false;return true;
}
int main(){
	scanf("%d%d",&n,&m);for (i=1;i<=n;i++){scanf("%s",ch);for (j=0;j<m;j++) if (ch[j]=='.') a[i][j+1]=0; else a[i][j+1]=1;}
	for (i=1;i<=n;i++) if (f(i)) for (j=1;j<=m;j++) b[i][j]=true;
	for (i=1;i<=m;i++) if (ff(i)) for (j=1;j<=n;j++) b[j][i]=true;
	for (i=1;i<=n;i++){bool flag=false;for (j=1;j<=m;j++) if (!b[i][j]){flag=true;if (a[i][j]) printf("#"); else printf(".");}
	if (flag) printf("\n");}return 0;
}