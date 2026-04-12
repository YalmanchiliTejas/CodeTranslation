#include<cstdio>
using namespace std;
bool read()
{
    char ch=getchar();
    while (ch!='#'&&ch!='.')
        ch=getchar();
    return ch=='#';
}
int n,m,cnt;
bool ma[10][10];
bool f[10][10];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            ma[i][j]=read();
            if (ma[i][j])
				cnt++;
		}
	ma[0][1]=true;
	f[0][1]=true;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
			if (!ma[i][j])
				continue;
			f[i][j]|=f[i-1][j]|f[i][j-1];
            if (ma[i-1][j]^ma[i][j-1]==false)
            {
            	printf("Impossible");
            	return 0;
			}
		}
	if (f[n][m]&&cnt==n+m-1)
    	printf("Possible");
	else
		printf("Impossible");
    return 0;
}