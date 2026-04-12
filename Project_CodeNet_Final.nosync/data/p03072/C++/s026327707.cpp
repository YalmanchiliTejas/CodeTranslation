#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
int n,a[21],maxx,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		if (a[i]>=maxx) ans++;
		maxx=max(maxx,a[i]);
	}
	cout<<ans;
	return 0;
}