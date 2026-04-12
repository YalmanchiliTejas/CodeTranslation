#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll d,n,i,f=0,s=0;
	d=1000000007;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	for(i=0;i<n-1;i++)
	{
		s=s-a[i];
		f+=a[i]*(s%d)%d;
		f=f%d;
	}
	cout<<f<<endl;
	return;
	
}






int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int t=1;
	//cin >> t;

	while (t--)
	{
		solve();
	}


	return 0;
}
