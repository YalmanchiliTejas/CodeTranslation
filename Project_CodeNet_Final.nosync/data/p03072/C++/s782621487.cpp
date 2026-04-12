#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int h[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>h[i];
	}
	int ans=0,ma=h[0];
	for (int i = 0; i < n; ++i)
	{
		if (ma<=h[i])
		{
			++ans;
			ma=h[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
