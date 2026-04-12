#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
#define MP make_pair
#define PB push_back
#define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
#define mod 1000000007
int n;
int a[100005];
multiset <int> se;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	f(i,0,n)
	{
		cin>>a[i];
	}
	se.insert(a[0]);
	int ans=1;
	f(i,1,n)
	{
		// cout<<ans<<endl;
		if(*(se.begin())<a[i])
		{
			auto itr=se.lower_bound(a[i]);
			itr--;
			se.erase(itr);
			se.insert(a[i]);
		}
		else
		{
			se.insert(a[i]);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}