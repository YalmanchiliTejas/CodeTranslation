#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005],t[1000005];
int main()
{
	int n;
	cin>>n>>s;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='o')
			t[i+1]=0;
		else
			t[i+1]=1;
	}
	t[n+1]=t[1];
	for(int i=0;i<8;i++)
	{
		a[0]=i&1;
		a[1]=(i>>1)&1;
		a[2]=(i>>2)&1;
		for(int j=2;j<=n+1;j++)
			a[j+1]=a[j-2]^t[j];
		if(a[0]^a[n]^a[1]^a[n+1]||a[1]^a[n+1]^a[2]^a[n+2])
			continue;
		for(int j=1;j<=n;j++)
		{
			if(a[j]^a[j-1])
				cout<<'W';
			else
				cout<<'S';
		}
		return 0;
	}
	cout<<"-1";

	return 0;
}