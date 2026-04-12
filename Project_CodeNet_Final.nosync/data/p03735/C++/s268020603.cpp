#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, idx=0;
int x[N], y[N];
set<pair<int, int> > reds, blues;

int get()
{
	int rmax=(--reds.end())->first;
	int rmin=reds.begin()->first;
	int bmax=(--blues.end())->first;
	int bmin=blues.begin()->first;
	return (rmax-rmin)*(bmax-bmin);
}

int work()
{
	for(int i=1;i<=n;i++)
	{
		if(x[i]>y[i])
			swap(x[i], y[i]);
		reds.insert({x[i], i});
		blues.insert({y[i], i});
	}
	int ans=1e18;
	for(int i=1;i<=2*n;i++)
	{
		ans=min(ans, get());
		int idx=reds.begin()->second;
		reds.erase({x[idx], idx});
		reds.insert({y[idx], idx});
		blues.erase({y[idx], idx});
		blues.insert({x[idx], idx});
		swap(x[idx], y[idx]);
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	int answer=work();
	cout<<answer;
	return 0;
}
