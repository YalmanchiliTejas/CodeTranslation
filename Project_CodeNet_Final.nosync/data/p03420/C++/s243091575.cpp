#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
const int mod=1e9+7;         
const int N=2e5+4;

ll f(int x)
{
	return 1LL*x*(x+1)/2;
}

int main()
{
	int n,k; scn(n); scn(k);

	ll ans=0;

	if(k==0)
	{
		lpri(1LL*n*n); return 0;
	}

	rep(i,k+1,n+1)
	{
		ll here=0;

		//(i-1)+x*i<=n
		int x=(n-(i-1))/i;

		ll cnt=(i-1)-k+1;

		here=(cnt*(x+1));

		int left = n - (x+1)*i;

		if(left>=k)
		here+=(left-k+1);

		ans+=here; //cout<<i<<" "<<here<<endl;
	}

	lpri(ans);

	return 0;
}

