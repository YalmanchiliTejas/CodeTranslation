#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<4;i++)
	{
		a[0]=i&1;
		a[1]=(i>>1)&1;
		for(int j=2;j<n;j++)
			a[j]=a[j-1]^a[j-2]^(s[j-1]=='x');
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			int t=(i-1+n)%n;
			int k=(i+1+n)%n;
			if(a[k]!=a[i]^a[t]^(s[i]=='x'))
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			for(int i=0;i<n;i++)
			{
				if(a[i])
					cout<<'W';
				else
					cout<<'S';
			}
			return 0;
		}
	}
	cout<<"-1";

	return 0;
}