#include<cstdio>
using namespace std;
int n,m;
char a[102][102];
bool line[102],column[102];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			if(a[i][j]=='#') {line[i]=true;column[j]=true;}
		}
	}
	for(int i=1;i<=n;++i) {
		if(!line[i]) continue;
		for(int j=1;j<=m;++j) {
			if(!column[j]) continue;
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 