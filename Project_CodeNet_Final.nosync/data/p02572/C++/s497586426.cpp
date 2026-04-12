#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
ll hell=pow(10,9)+7;
void solve(){
	ll n,sum=0,res=0;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	sum%=hell;
	for(ll i=0;i<n;i++){
		sum=(sum-v[i])%hell;
		res+=(v[i]*sum)%hell;
		res%=hell;
	}
	if(res<0)
		res+=hell;
	cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    clock_t z=clock();
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++)
        solve();
    debug("Total Time:%.4Lf\n",(ld)(clock()-z)/CLOCKS_PER_SEC);
}