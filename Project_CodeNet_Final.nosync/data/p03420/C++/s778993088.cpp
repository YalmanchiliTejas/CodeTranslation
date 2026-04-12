#include<bits/stdc++.h>
using namespace std;
inline void read(long long &x)
{
	x=0;
	long long p=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	x*=p;
}
long long n,k;
int main()
{
//	freopen(".in","r",stdin);
//	freopen("a.out","w",stdout);
	read(n);read(k);
	if(k>=(n+1)/2)return cout<<(1ll+n-k)*(n-k)/2<<endl,0;
	if(k==0)return cout<<n*n<<endl,0;
	long long ans=0;
	for(long long i=n;i>=k+1;i--)
	{
		long long block=(n/i);
		long long yu=n%i;
		ans+=block*(i-k);
		if(yu>=k)ans+=(1ll+yu-k);
	}
	cout<<ans<<endl;
	return 0;
}