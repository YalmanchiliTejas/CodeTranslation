#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mset(m,v) memset(m,v,sizeof(m))
#define pr(a,s) printf("Case #%lld: %lld\n",a,s)
#define mod 1000000007
#define mp make_pair
#define all(a)                a.begin(),a.end()
#define pb push_back
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define se second
#define fi first
#define pi 3.14159265358979323
#define pii pair<ll,ll>
 
const ll inf = 1e15;
const int MAXM = 3e3+4;
const int MAXN = 1e5+1;

ll arr[MAXM], dp[MAXM][MAXM];

ll solve(int st, int end)
{
	if (st == end)	return arr[st];
	if (dp[st][end] != -1)	return dp[st][end];
	ll ret = -inf;
	ret = max(ret, max(arr[st]-solve(st+1,end) , arr[end]-solve(st,end-1)));
	return dp[st][end] = ret;
}

int main()
{
	mset(dp,-1);
	int n;
	cin>>n;
	ll sum = 0;
	for (int i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll x = solve(1,n);
	cout << x << endl;
}