#include<bits/stdc++.h>
using  namespace std;

#define ll long long
#define re register
#define pb(x) push_back(x)
#define ce(x) cout << x << endl;

using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
#define scl1(a)             scanf("%lld", &a)
#define scl2(a, b)          scanf("%lld %lld", &a, &b)

#define rep(i,x,n,inc) for(i=x ; i<n ; i+=inc)
const int N=(int)3e3+5;
int n;
ll dp[N][N],a[N];
ll f(ll i,ll j){
	 if (i<1 or j<1 or j>n or i>n) return 0;
    if (i==j) return a[i];
    if (i>j) return 0;
    if (dp[i][j]!=(-1)) return dp[i][j];
    dp[i][j] = max(a[i]+min(f(i+2,j),f(i+1,j-1)),a[j]+min(f(i,j-2),f(i+1,j-1)));
	return dp[i][j];
}

int32_t main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll t,i,j,z,k,s=0;

memset(dp,-1,sizeof(dp));
cin>>n;
rep(i,1,n+1,1){
	cin>>a[i];
	s+=a[i];
}
cout<<(2*f(1,n)-s)<<endl;
}
