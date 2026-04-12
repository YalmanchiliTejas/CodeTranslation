#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(v) (ll((v).size()))
#define forn(i,n) for(ll i=0;i<(n);i++)
#define forr(i,n) for(ll i=(n)-1;i>=0;i--)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
#define clr(x) memset(x,0,sizeof(x))

const ll N =3030;
ll a[N],vis[N][N],ans[N][N],n;

void solve(ll l, ll r)
{
	if(vis[l][r])return;
	vis[l][r]=1;
	ll k = r-l+1;k=n-k;

	if(l==r)
	{
		ans[l][r]=a[l];
		if(k%2==1)ans[l][r]*=-1;
		return;
	}

	solve(l+1,r);
	solve(l,r-1);
	if(k%2==0)ans[l][r]=max(a[l]+ans[l+1][r],a[r]+ans[l][r-1]);
	else ans[l][r]=min(ans[l+1][r]-a[l],ans[l][r-1]-a[r]);
}

int main()
{
    ios_base::sync_with_stdio(false);

	clr(vis);
	cin>>n;forn(i,n)cin>>a[i];
	solve(0,n-1);
	cout<<ans[0][n-1]<<endl;

}
