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

int Mod(int a) {
	return (a+mod)%mod;
}
int Mul(int a, int b) {
	return Mod(Mod(a) * Mod(b));
}
int Add(int a, int b) {
	return Mod(Mod(a) + Mod(b));
}
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


signed main(){
    fast;
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
    int tt = 1;
    //cin>>tt;
    for(int tc = 1; tc <= tt; tc++) {
        int n,x,m;
        cin>>n>>x>>m;
        int ans = x;
        vector<int>chk;
        chk.pb(x);
        map<int,int>vis;
        map<int,int>si;
        vis[x] = 1;
        si[x] = 0;
        for(int i = 1; i < n; i++) {
			x *= x;
			x %= m;
			if(!vis[x]) {
				vis[x] = 1;
				si[x] = i;
				chk.pb(x);
				ans += x;
			}
			else {
				break;
			}
		}
		int rs = 0;
		for(int i = si[x]; i < (int)chk.size(); i++) rs += chk[i];
		int bakin = n-chk.size();
		int sz = chk.size() - si[x];
		int jabe = bakin/sz;
		ans += (jabe*rs);
		int aro = bakin % sz;
		for(int i = 0; i < aro; i++) ans += chk[si[x]+i];
		cout<<ans<<endl;
			
        
        
    }



return 0;
}
