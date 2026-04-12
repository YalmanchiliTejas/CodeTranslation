#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <map>
#define fr first
#define sc second
#define pii pair<int,bool>
#define mp make_pair
using namespace std;
const int maxn=1e6+10;
int n,a[maxn];
map<pii,long long>dp[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0][mp(0,0)]=0;
	for (int i=1;i<=n;i++)
	 for (auto j:dp[i-1])
	 {
	 	if (!j.fr.sc) 
	 	{
	 		if (dp[i].count(mp(j.fr.fr+1,1))) dp[i][mp(j.fr.fr+1,1)]=max(dp[i][mp(j.fr.fr+1,1)],j.sc+a[i]);
	 		else dp[i][mp(j.fr.fr+1,1)]=j.sc+a[i];
	 	}
	 	if ((n-i+1)/2+j.fr.fr>=(n/2)) 
	 	{
	 		if (dp[i].count(mp(j.fr.fr,0))) dp[i][mp(j.fr.fr,0)]=max(dp[i][mp(j.fr.fr,0)],j.sc);
	 		else dp[i][mp(j.fr.fr,0)]=j.sc;
	 	}
	 }
	printf("%lld\n",max(dp[n][mp(n/2,0)],dp[n][mp(n/2,1)]));
return 0;
}