#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<map>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
int A,B;
int dis[15][15];
int ed[105][105];
int main()
{
	read(A);
	read(B);
	memset(ed,0,sizeof(ed));
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
		{
			read(dis[i][j]);
			for(int a=0;a<=100;a++)
				for(int b=0;b<=100;b++)
					ed[a][b]=max(ed[a][b],dis[i][j]-a*i-b*j);
		}
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
		{
			long long ans=12345678987654321ll;
			for(int a=0;a<=100;a++)
				for(int b=0;b<=100;b++)
					ans=min(ans,1ll*a*i+b*j+ed[a][b]);
			if(ans!=dis[i][j])
			{
				printf("Impossible\n");
				return 0;
			}
		}
	printf("Possible\n");
	cout<<202<<' '<<101*101+200<<endl;
	for(int i=1;i<=100;i++)
		cout<<i<<' '<<i+1<<" X"<<endl;
	for(int i=1;i<=100;i++)
		cout<<i+101+1<<' '<<i+101<<" Y"<<endl;
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			cout<<i+1<<' '<<j+101+1<<' '<<ed[i][j]<<endl;
	cout<<1<<' '<<102<<endl;
	return 0;
}