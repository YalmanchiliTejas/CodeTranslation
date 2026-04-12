#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=111111;
int A[maxn];
bool vis[maxn];
int main()
{
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i) scanf("%d",A+i);
	LL Ans=0;
	for(int i=1;i<N;++i)
	{
		LL ans=0;
		for(int j=0,k=N-1;j<N-1-i&&!vis[j]&&!vis[k]&&j!=k;j+=i,k-=i)
		{
			vis[j]=vis[k]=true;
			ans+=(A[j]+A[k]);
			Ans=max(Ans,ans);
//			printf("%d %d %d %lld\n",i,j,k,ans);
		}
		for(int j=0,k=N-1;j<N-1-i&&vis[j]&&vis[k];j+=i,k-=i) vis[j]=vis[k]=false;
	}
	printf("%lld",Ans);
	return 0;
}