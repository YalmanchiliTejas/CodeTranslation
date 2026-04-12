#include<cstdio>
#include<algorithm>
using namespace std;const int N=110;bool book1[N];bool book2[N];
char mde[N][N];int n;int m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",mde[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)book1[i]|=(mde[i][j]=='#'),book2[j]|=(mde[i][j]=='#');
	for(int i=1;i<=n;i++)
		{
			if(book1[i]==false)continue;
			for(int j=1;j<=m;j++)if(book2[j])printf("%c",mde[i][j]);printf("\n");
		}return 0;
	
}