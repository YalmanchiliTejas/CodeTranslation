#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=3050;
int a[N];
ll dp[N][N];
bool was[N][N];
ll DP(int l, int r)
{
if(was[l][r] || l>r) return dp[l][r];
was[l][r]=1;
dp[l][r]=max(a[l]-DP(l+1,r),a[r]-DP(l,r-1));
return dp[l][r];
}
int main()
{
int n;
scanf("%i",&n);
for(int i=1;i<=n;i++)
scanf("%i",&a[i]);
printf("%lld",DP(1,n));
return 0;
}