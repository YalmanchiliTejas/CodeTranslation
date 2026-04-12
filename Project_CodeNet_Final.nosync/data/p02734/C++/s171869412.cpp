         /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
const int mod=998244353;         
const int N=3e3+4;

//dp[i][j] tells the no. of subset formed considering the first i eleements 
//so that their sum is j.

void add_self(int &a,int b)
{
	a+=b;

	if(a>=mod)
	a-=mod;
}

int dp[N][N];

int main()
{
	int n,s;

	scn(n); scn(s);

	//dp[0][0]=1;

	int ans=0;

	for(int i=1;i<=n;i++)
	{
		int val; scn(val);

		for(int j=0;j<=s;j++)
		{
			dp[i][j]=dp[i-1][j];

			if(j-val>=0)
			add_self(dp[i][j],dp[i-1][j-val]);
		}

		dp[i][val]+=i;

		add_self(ans,dp[i][s]);
	}

	pri(ans);

    return 0;
}