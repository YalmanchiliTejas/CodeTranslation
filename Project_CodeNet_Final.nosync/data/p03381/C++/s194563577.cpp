#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n],b[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	for (int i = 0; i < n; ++i)
	{
		if (a[i]<=b[n/2-1])
		{
			cout<<b[n/2]<<endl;
		}
		else
		{
			cout<<b[n/2-1]<<endl;
		}
	}
	return 0;
}
