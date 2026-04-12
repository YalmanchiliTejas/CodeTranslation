#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define Endl '\n'
#define cont continue
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define pb push_back
#define mp make_pair
#define mem(x) memset(x, 0, sizeof(x))

const ll inf=1e18;
const int mod=1e9+7;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
const int mxn = 2e5+10;

//ll fact[mxn];
//ll in_fact[mxn];
//fact[0] = 1;
//for(ll i = 1; i < mxn; i++) {
	//fact[i] = (i*fact[i-1])%mod;
//}
//in_fact[mxn-1] = bigmod(fact[mxn-1],mod-2);
//for(ll i = mxn-2; i >= 0; i--) {
	//in_fact[i] = (in_fact[i+1] * (i+1))%mod;
//}
//ll c(ll n,ll r) {
	//ll ans = (fact[n] * (in_fact[r] * in_fact[n-r]%mod))%mod;
	//return ans;
//}
int Mod(int a) {
	return a%mod;
}
int Mul(int a, int b) {
	return Mod(Mod(a) * Mod(b));
}
int Add(int a, int b) {
	return Mod(Mod(a) + Mod(b));
}

signed main(){
    fast;
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
    int tt = 1;
    //cin>>tt;
    for(int tc = 1; tc <= tt; tc++) {
        int n;
        cin>>n;
        int ip[n];
        int ans = 0;
        for(int i = 0; i < n; i++) cin>>ip[i];
        int cs[n+1];
        cs[0] = 0;
        for(int i = 1; i <= n; i++) {
			cs[i] = cs[i-1] + ip[i-1];
		}
		for(int i = 0; i < n; i++) {
			ans = Add(ans , Mul(ip[i],(cs[n] - cs[i+1])));
		}
		cout<<ans<<endl;
        
    }



return 0;
}
