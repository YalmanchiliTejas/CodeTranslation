#include<bits/stdc++.h>
using namespace std;
const int pi=3.1415926535897932384626433832795;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
int s[100005],a[100005],n;
char p[100005];
int main()
{
	cin>>n;
	cin>>p;
	for(int i=0;i<n;i++)
	{
		if(p[i]=='o')
			a[i+1]=0;
		else
			a[i+1]=1;
	}
	a[n+1]=a[1];
	for(int i=0;i<8;i++)
	{
		s[0]=i&1;
		s[1]=(i>>1)&1;
		s[2]=(i>>2)&1;
		for(int j=2;j<=n+1;j++)
			s[j+1]=s[j-2]^a[j];
		if(s[0]^s[n]^s[1]^s[n+1]||s[1]^s[n+1]^s[2]^s[n+2])
			continue;
		for(int j=1;j<=n;j++)
			cout<<(s[j]^s[j-1]?"W":"S");
		return 0;
	}
	puts("-1");
	return 0;
}