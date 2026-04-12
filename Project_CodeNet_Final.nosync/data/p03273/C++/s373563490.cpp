#include<cstdio>
#include<set>
using namespace std;
int H,W;
char ch[105][105];
bool tf;
set <int> S;
int main()
{
	scanf("%d %d",&H,&W);
	for(int i=1;i<=H;i++)
	{
		tf=true;
		for(int j=1;j<=W;j++)
		{
			scanf(" %c",&ch[i][j]);
			if(ch[i][j]=='#')
			tf=false;
		}
		if(tf)
		{
			H--;
			i--;
		}
	}
	for(int i=1;i<=W;i++)
	{
		tf=true;
		for(int j=1;j<=H;j++)
		if(ch[j][i]=='#')
		{
			tf=false;
			break;
		}
		if(tf)
		S.insert(i);
	}
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(S.find(j)==S.end())
			printf("%c",ch[i][j]);
		}
		printf("\n");
	}
	return 0;
}