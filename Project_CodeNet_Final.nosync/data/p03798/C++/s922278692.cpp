#include <bits/stdc++.h>
using namespace std;
const int M=300000;
int n;
string s;
int a[M];
int main()
{
	cin>>n>>s;
	s=s+s;
	for(int i1=0;i1<2;i1++)
		for(int i2=0;i2<2;i2++)
	{
		a[0]=i1;
		a[1]=i2;
		for(int j=2;j<=n+1;j++)
		{
			if ((s[j-1]=='o'&&a[j-1]==0)||(s[j-1]=='x'&&a[j-1]==1))
				a[j]=a[j-2];
			if ((s[j-1]=='o'&&a[j-1]==1)||(s[j-1]=='x'&&a[j-1]==0))
				a[j]=1-a[j-2];
		}
		if (a[n]==a[0]&&a[n+1]==a[1])
		{
			for(int j=0;j<n;j++)
				cout<<(a[j]?"W":"S");
			return 0;
		}
	}
	cout<<-1;
	return 0;	
} 