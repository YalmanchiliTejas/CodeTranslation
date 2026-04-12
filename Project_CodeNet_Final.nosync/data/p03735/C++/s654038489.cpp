#include <iostream>
#include <set>
#include <algorithm>
#define int long long
using namespace std;
pair <int,int> a[200005],b[500005];
multiset <int> s;
multiset <int> s2;
int c[500005];
signed main(int argc, char** argv) {
	int n,cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first >> a[i].second;
		b[++cnt]={a[i].first,i};
		b[++cnt]={a[i].second,i};
		if(a[i].first>a[i].second) swap(a[i].first,a[i].second);
	}
	sort(a+1,a+n+1);
	int mn=2e9,MN=2e9,mx=0,MX=0;
	for(int i=1;i<=n;i++) mn=min(mn,a[i].first);
	for(int i=1;i<=n;i++) MN=min(MN,a[i].second);
	for(int i=1;i<=n;i++) mx=max(mx,a[i].first);
	for(int i=1;i<=n;i++) MX=max(MX,a[i].second);
	int ans=(MX-MN)*(mx-mn);
	sort(b+1,b+cnt+1);
	cnt=0;
	int l=1;
	for(int i=1;i<=n*2;i++)
	{
		if(!c[b[i].second]) ++cnt;
		++c[b[i].second];
		while(cnt==n)
		{
			ans=min(ans,(MX-mn)*(b[i].first-b[l].first));
			--c[b[l].second];
			if(c[b[l].second]==0)
				--cnt;
			++l;
		}
	}
	cout << ans;
	return 0;
}