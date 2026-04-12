#include<bits/stdc++.h>
using namespace std;
long long n;
long long x,m;
int sa[100100];
long long add[100010];
int main()
{
	cin>>n>>x>>m;
	int Bit=1;
	long long l,r;
	for(long long a=x;;a=(a*a)%m,Bit++)
	{
		if(!sa[a]) sa[a]=Bit;
		else
		{
			l=sa[a],r=Bit-1;
			break;
		}
		add[Bit]=add[Bit-1]+a;
	}
	long long len=r-l+1;
	long long ans=add[min(n,l-1)];
	n=max(0ll,n-l+1);
	if(n) ans+=(add[r]-add[l-1])*(n/len)+(add[n%len+l-1]-add[l-1]);
	cout<<ans;
	return 0;
}