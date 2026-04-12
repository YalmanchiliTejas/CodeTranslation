#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long sum=1,qwq=1,m,ans=0;
long long qwqqwq()
{
	for (;n;--n,sum=(sum-3)/2,qwq=(qwq-1)/2)
	{
		if (m==sum/2+1)	return ans+(qwq-1)/2+1;
		else if (m<=sum/2)
			if (m==1) return ans;
			else m--;
		else if (m==sum) return ans+qwq;
		else m=m-sum/2-1,ans+=(qwq-1)/2+1;
	}
	return ans+1;
} 
int main()
{
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;++i) sum=sum*2+3,qwq=qwq*2+1;
	cout<<qwqqwq();
}