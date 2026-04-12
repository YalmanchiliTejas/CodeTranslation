#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	cin>>a>>b;
	if (a == b)
	{
		cout<<"Yes"<<endl;
	}
	else if (a > b)
	{
		cout<<"No"<<endl;
	}
	return 0;
}