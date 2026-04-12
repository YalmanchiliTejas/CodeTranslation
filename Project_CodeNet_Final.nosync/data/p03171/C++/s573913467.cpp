#include <bits/stdc++.h> /**  I'm Klaus, NicKlaus :v **/
using namespace std;
#define ms(a,v) memset(a,v,sizeof a)
#define ll long long
ll gcd(ll x, ll y){return (y ? gcd(y, x%y) : x); }
ll lcm(ll x, ll y){return x*(y/gcd(x,y));}
ll oo = 1e16+1;
const int nax = 3003;
int n;
ll a[nax];
ll dp[nax][nax][3];
ll go(int l, int r, int f){
	if( l > r ) return 0;
	if(dp[l][r][f] != -1) return dp[l][r][f];
	ll& ans = dp[l][r][f];
	if(f){
		ans = oo;
		ans = min(ans, go(l+1,r,f^1)-a[l]);
		ans = min(ans, go(l,r-1,f^1)-a[r]);
	}else{
		ans = -oo;
		ans = max(ans, go(l+1,r,f^1)+a[l]);
		ans = max(ans, go(l,r-1,f^1)+a[r]);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifdef LOCAL_JUDGE
		//freopen("in_out/in.txt", "rt", stdin);
		//freopen("int_out/out.txt", "wt", stdout);
	#endif
	ms(dp,-1);
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<go(0,n-1,0)<<endl;
 	return 0;
}
