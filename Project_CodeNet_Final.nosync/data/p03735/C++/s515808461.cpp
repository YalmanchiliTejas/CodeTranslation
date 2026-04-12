#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
pair<long,long>p[1<<18];
long MIN=1e9,MAX;
main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first>>p[i].second;
		if(p[i].first>p[i].second)swap(p[i].first,p[i].second);
		MIN=min(MIN,p[i].first);
		MAX=max(MAX,p[i].second);
	}
	long maxr=0,minb=1e9;
	for(int i=0;i<n;i++)
	{
		maxr=max(maxr,p[i].first);
		minb=min(minb,p[i].second);
	}
	long ans1=(maxr-MIN)*(MAX-minb);
	sort(p,p+n);
	minb=p[0].first,maxr=p[n-1].first;
	long ans2=(MAX-MIN)*(maxr-minb);
	long minsecond=MAX+1;
	for(int i=0;i<n;i++)
	{
		minb=min(min(p[i].second,i==n-1?MAX+1:p[i+1].first),minsecond);
		minsecond=min(minsecond,p[i].second);
		maxr=max(maxr,p[i].second);
		ans2=min(ans2,(MAX-MIN)*(maxr-minb));
	}
	cout<<min(ans1,ans2)<<endl;
}