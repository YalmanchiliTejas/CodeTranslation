#include<bits/stdc++.h>
#define N (200009)
#define LL long long
using namespace std;

LL n,ans,x,y;
pair<LL,LL>a[N];
multiset<LL>r,b;

int main()
{
	cin>>n;
	for (int i=1; i<=n; ++i)
	{
		cin>>x>>y;
		if (x>y) swap(x,y);
		b.insert(x); r.insert(y);
		a[i]=make_pair(x,y);
	}
	sort(a+1,a+n+1);
	ans=(*b.rbegin()-*b.begin())*(*r.rbegin()-*r.begin());
	for (int i=1; i<=n; ++i)
	{
		b.erase(b.find(a[i].first)); r.insert(a[i].first);
		r.erase(r.find(a[i].second)); b.insert(a[i].second);
		ans=min(ans,(*b.rbegin()-*b.begin())*(*r.rbegin()-*r.begin()));
	}
	cout<<ans<<endl;
}