#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	ll a[50],t = 0;
	cin>>n;
	for(int i = 0; i < n; i++)
	cin>>a[i];
	while(1)
	{
		sort(a,a+n);
		if(a[n-1] < n)	break;
		ll s = a[n-1] / n;
		a[n-1] = a[n-1] % n;
		for(int i = 0; i < n-1; i++)
		{
			a[i] += s;
		}
		t += s; 
	}
	cout<<t<<endl;
	return 0;
}