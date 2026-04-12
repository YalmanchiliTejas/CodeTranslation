#include <bits/stdc++.h>
#define F first
#define S second
#define ld long douroote
#define pb push_back
#define ll long long
#define INF 0x7f7f7f7f
#define sc(a) scanf("%d",&a)
#define scll(a) scanf("%I64d",&a)
#define scc(a) scanf(" %c",&a)
#define scs(a) scanf(" %s",a)
#define me(a,b) memset(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define allr(a,n) a,a+n
#define loop(a,s,e) for(ll a=s;a<=e;a++)
#define read_arr(a,s,n) for(ll i=s;i<n+s;i++){sc(a[i]);}
#define read_arr_ll(a,s,n) for(ll i=s;i<n+s;i++){scll(a[i]);}
#define open(in,out) freopen(in,"r",stdin);freopen(out,"w",stdout);
#define err(a,s) cerr<<a<<s;
#define err_arr(a,s,n) for(ll i=s;i<n+s;i++){cerr<<a[i]<<" ";}cerr<<endl;
#define prtll(x) printf("%lld",x);
#define prt(x) printf("%d",x);
using namespace std;
const int N=3e3+55;
ll dp[N][N];
ll a[N];
int n;

ll bt(int l , int r)
{
    if(r<l){return 0;}
	if(l==r)
        return a[l];
	ll &ret=dp[l][r];
    if(ret!=-1)
    return ret;
	ret=max(min(bt(l+2,r)-a[l+1],bt(l+1,r-1)-a[r])+a[l],
            min(bt(l+1,r-1)-a[l],bt(l,r-2)-a[r-1])+a[r]);
	return ret;
}
/**
bt(l+1,r,-1)=min(bt(l+2,r)-a[l+1],bt(l+1,r-1)-a[r])+a[l];
bt(l,r-1,-1)=min(bt(l+1,r-1,1)-a[l],bt(l,r-2)-a[r])
**/
int main()
{
	memset(dp,-1,sizeof dp);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<bt(0,n-1)<<endl;
	return 0;
}
