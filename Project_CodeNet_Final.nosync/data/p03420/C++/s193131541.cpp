#include<bits/stdc++.h>
using namespace std;
#define N 100005
long long n,m,a[N],ans;
int main()
{
	scanf("%lld%lld",&n,&m);
	if(m==0) {cout<<n*n<<endl;return 0;}
	for(long long i=m+1;i<=n;i++)
	{
		ans+=(n/i)*(i-m);
		if(n%i>=m) ans+=n%i-m+1;
	}
	cout<<ans<<endl;
}