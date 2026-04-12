#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int date[100000];
bool bit[31];
int did[31];

int main()
{
	memset(bit,false,sizeof(bit));
	while(true)
	{
		int a,b;
		scanf("%d,%d",&a,&b);
		if(a==0&&b==0)break;
		bit[b]=true;
		date[a]=b;
	}
	int k=1;
	for(int i=30;i>-1;i--)
	{
		if(bit[i]==true)
		{
			did[i]=k;
			k++;
		}
	}
	int j;
	while(scanf("%d",&j)!=EOF)
	{
		printf("%d\n",did[date[j]]);
	}
	return 0;

}