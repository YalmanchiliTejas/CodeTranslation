#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
const int mod=998244353;
typedef long long LL;
LL dp[maxn]; int a[maxn];
int main(void)
{
	int n,s; scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	LL res=0;
	for(int i=1;i<=n;i++)
	{
		dp[0]++; // 增加一次计数，表示从i 到 i 的容量为0时方案加一，这里相当于插入一个L, 
		for(int j=s;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%mod;
		res=(res+dp[s])%mod; // 计数答案每次增加量，当R等于i时 L=1 到 i 时的方案数 
	}
	printf("%lld\n",res);
	return 0;
}