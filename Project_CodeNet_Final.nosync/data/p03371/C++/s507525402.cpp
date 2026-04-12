#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int a[5];
	for(int i  = 0; i<5;i++)cin >> a[i];
	int ans = 0;
	if(a[0]+a[1]>a[2]*2)
	{
		int mi = min(a[3],a[4]);
		ans += mi*2*a[2];
		a[3] -= mi;
		a[4] -= mi;
	}

	if(a[0]>a[2]*2)
	{
		ans += a[3]*2*a[2];
		a[3]=0;
	}

	if(a[1]>a[2]*2)
	{
		ans += a[4]*2*a[2];
		a[4]=0;
	}
	ans += a[3]*a[0];
	ans += a[4]*a[1];
	cout<<ans<<endl;
	return 0;
}
