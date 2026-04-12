#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<long long, long long>
#define f first
#define s second
#define debug cout<<"here\n" 
#define MOD 1000000007

const int MAXN = 2e5 +15;
 
using namespace std;

ll modexp(ll a, ll p, ll mod){
	if(p == 0) return 1;
	ll ans = modexp(a,p/2,mod);
	ans = (ans*ans)%mod;
	if(p%2) return (a*ans)%mod;
	else return ans;
}

void solve(){	
	int n; cin>>n;
	ll s = 0, t=0;
	for(int i=0; i<n; i++){
		ll y; cin>>y;
		s += y;
		s %= MOD;
		t += (y*y)%MOD;
		t %= MOD;
	}
	cout<<(((s*s)%MOD-t+MOD)%MOD*modexp(2,MOD-2,MOD))%MOD;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);	
	cout<<fixed<<setprecision(12);

	int t =1; //cin>>t;
	for(int i=1; i<= t; i++){
		solve();
		cout<<"\n";
	}
	
	return 0;
}