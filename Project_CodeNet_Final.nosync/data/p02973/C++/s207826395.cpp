#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,d[100000];
	cin>>n;
	for(int i=0;i<n;i++)
	  d[i]=1;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		d[upper_bound(d,d+n,-a)-d]=-a;
	}
	cout<<lower_bound(d,d+n,1)-d<<endl;
	return 0;
}