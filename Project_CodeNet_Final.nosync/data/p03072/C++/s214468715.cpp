#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,t=1,m=0;
	cin>>n;
	int a[n+1];
	for(i=1;i<=n;i++)
	cin>>a[i];
	m=a[1];
	for(i=2;i<=n;i++)
	if(a[i]>=m)
	{
		t++;
		m=a[i];
	}
	cout<<t;
	return 0;
 } 