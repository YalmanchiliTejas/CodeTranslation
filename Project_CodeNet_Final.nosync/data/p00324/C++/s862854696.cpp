#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<long long,int> P;
P pp[200001];
long long sum[200001];
int main(void)
{
	int n,i,j,d[200001],mid,low,high,mx;
	scanf("%d",&n);
	for(i=1;i<=n;i++)	scanf("%d",&d[i]);
	sum[0]=0;
	for(i=1;i<=n;i++)	sum[i]=sum[i-1]+d[i];
	for(i=0;i<=n;i++){
		pp[i].first=sum[i];	pp[i].second=i;
	}
	sort(pp,pp+n+1);
//	for(i=0;i<=n;i++)	{
//		printf("   %d %d\n",pp[i].first,pp[i].second);
//	}
	mx=0;
	for(i=0;i<n;i++)	{
		low=0;	high=n;
		while(low<=high)	{
			mid=(low+high)/2;
			if(pp[mid].first<=sum[i])	low=mid+1;
			else high=mid-1;
		}
		mx=max(mx,pp[high].second-i);
	}
    printf("%d\n",mx);
    return 0;
}
