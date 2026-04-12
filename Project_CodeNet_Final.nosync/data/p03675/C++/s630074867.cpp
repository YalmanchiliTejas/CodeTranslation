#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int p=n/2, q=n/2 + 1;
	for(int i=1;i<=n;i++)
	{
		if(i%2)
			b[q++]=a[i];
		else
			b[p--]=a[i];
	}
	if(n%2)
		reverse(b+1, b+n+1);
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	return 0;
}
