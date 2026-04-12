#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e5+10;
vector<int>v;
int a[maxn],n,ans; 
int cnt[maxn];
set<int>s;
inline int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
	{
		set<int>::iterator it=s.upper_bound(-getid(a[i]));
		if(it!=s.end())
		{
			if(++cnt[getid(a[i])]==1)
			{
//				printf("!%d\n",a[i]);
				s.insert(-getid(a[i]));
			}
			if(--cnt[-*it]==0)
			{
//				printf("@%d\n",-*it);
				s.erase(it);
			}
		}
		else
		{
//				printf("#%d\n",a[i]);
			++cnt[getid(a[i])];
			s.insert(-getid(a[i]));
			ans++;
		}
	}
	printf("%lld\n",ans);
}
/*
6 
3 2 1 3 1 1
*/