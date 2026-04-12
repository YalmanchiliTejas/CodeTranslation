#include<iostream>
#include<cstdio>
int p[400008];
int a[400008];
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
		s[i]=='o'?p[i+1]=0:p[i+1]=1;
	p[n+1]=p[1];
	for(int i=0;i<8;i++)
	{
		a[0]=i&1;
		a[1]=(i>>1)&1;
		a[2]=(i>>2)&1;
		for(int j=2;j<=n+1;j++)
		{
			a[j+1]=a[j-2]^p[j];
		}
		if(a[0]^a[n]^a[1]^a[n+1] || a[1]^a[n+1]^a[2]^a[n+2])continue;
		for(int j=1;j<=n;j++)
			cout<<(a[j]^a[j-1]?"W":"S");
		return 0;
	}
	cout<<"-1"<<endl;
	return 0;
}