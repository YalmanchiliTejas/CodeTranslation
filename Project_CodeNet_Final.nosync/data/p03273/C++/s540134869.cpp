#include<bits/stdc++.h>
using namespace std;
char ch[110][110];
bool visit[1010],visit2[1010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(visit2,false,sizeof(visit2));
	memset(visit,false,sizeof(visit));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) cin>>ch[i][j];
	for (int i=1;i<=n;i++)
	{
		bool flag=false;
		for (int j=1;j<=m;j++) if (ch[i][j]=='#')
		{
			flag=true;
			break;
		}
		if (!flag) visit[i]=true;
	}
	for (int i=1;i<=m;i++)
	{
		bool flag=false;
		for (int j=1;j<=n;j++) if (ch[j][i]=='#')
		{
			flag=true;
			break;
		}
		if (!flag) visit2[i]=true;
	}
	for (int i=1;i<=n;i++)
	{
		bool flag=false;
		for (int j=1;j<=m;j++) if (!visit[i] && !visit2[j])
		{
			cout<<ch[i][j];
			flag=true;
		}
		if (flag) cout<<endl;
	}
}