#include <bits/stdc++.h>
#define int long long
#define double long double
#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define rt return
#define ct continue
#define br break
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define mmod 1000000007
#define pmod 998244353
using namespace std;
int gcd(int a,int b){
    while (b) b^=a^=b^=a%=b;
    return a;
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int bigmod(int b,int p,int m){
    int ans=1;
    b%=m;
    if (!b) return 0;
    while (p){
        if (p&1) ans=(ans*b)%m;
        p>>=1;
        b=(b*b)%m;
    }
    return ans;
}
void recur(){
	
	
	
}
void solve(){
	int n,x,m;
	cin>>n>>x>>m;
	int occ[m];
	for (int i=0; i<m; i++) occ[i]=0;
	int p=x%m;
	occ[p]=1;
	for (int i=2; i<=n;i++){
		p*=p;
		p%=m;
		if (occ[p]){
			int ans=0,d=i-occ[p];
			for (int j=0; j<m; j++){
				if (!occ[j]) continue;
				if (occ[j]<occ[p]) ans+=j;
				else ans+=j*((n-occ[j])/d+1);
			}
			cout<<ans;
			return;
		}
		occ[p]=i;
	}
	int ans=0;
	for (int i=0; i<m; i++){
		if (occ[i]) ans+=i;
	}
	cout<<ans;
	
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while (t--) solve();
}