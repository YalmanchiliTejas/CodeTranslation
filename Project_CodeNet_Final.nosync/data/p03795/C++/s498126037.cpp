#include<bits/stdc++.h>
using namespace std;
long long x;
int n;
int main()
{
	cin>>n;
	x=n*800;
	while(n>=15)
	{
		n-=15;
		x=x-200;
	}
	cout<<x;
	return 0;
}
