#include<cstdio>
#define maxn 105
using namespace std;
char s[maxn][maxn];
bool h[maxn],l[maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		bool flag=0;
		for(int j=1;j<=m;j++)if(s[i][j]=='#'){flag=1;break;}
		if(!flag)h[i]=1;
	}
	for(int j=1;j<=m;j++){
		bool flag=0;
		for(int i=1;i<=n;i++)if(s[i][j]=='#'){flag=1;break;}
		if(!flag)l[j]=1;
	}
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=1;j<=m;j++){
			if(!h[i]&&!l[j]){
				flag=1;
				putchar(s[i][j]);
			}
		}
		if(flag)putchar('\n');
	}
	return 0;
}