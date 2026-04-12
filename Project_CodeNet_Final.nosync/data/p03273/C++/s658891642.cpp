#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N=110;
char a[N][N];
int n,m,r[N],c[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='#')r[i]=c[j]=1;
	for(int i=1;i<=n;i++){
		if(!r[i])continue;
		for(int j=1;j<=m;j++)
			if(c[j])cout<<a[i][j];
		puts("");
	}
	return 0;
}