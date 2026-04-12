#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> vx[100001],vy[100001];
int par[100001];
int fnd(int k)
{
	return par[k]==k?k:par[k]=fnd(par[k]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vx[i]=make_pair(x,i);
		vy[i]=make_pair(y,i);
	}
	sort(vx+1,vx+n+1);
	sort(vy+1,vy+n+1);
	vector<pair<int,pair<int,int>>> diff;
	for (int i=1;i<n;++i)
	{
		diff.push_back(make_pair(vx[i+1].first-vx[i].first,make_pair(vx[i].second,vx[i+1].second)));
		diff.push_back(make_pair(vy[i+1].first-vy[i].first,make_pair(vy[i].second,vy[i+1].second)));
	}
	sort(diff.begin(),diff.end());
	long long ans=0;
	for (int i=1;i<=n;++i)
		par[i]=i;
	for (size_t i=0;i<diff.size();++i)
		if (fnd(diff[i].second.first)!=fnd(diff[i].second.second))
		{
			ans+=diff[i].first;
			par[fnd(diff[i].second.first)]=fnd(diff[i].second.second);
		}
	printf("%lld",ans);
	return 0;
}
