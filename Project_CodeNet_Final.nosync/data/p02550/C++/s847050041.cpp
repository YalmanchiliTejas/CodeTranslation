#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
void solve(){
	ll n,x,m,res=0;
	cin>>n>>x>>m;
	vector<ll> v(1,x);
	set<ll> s;
	s.insert(x);
	while(1){
		x=(x*x)%m;
		if(s.find(x)!=s.end())
			break;
		v.push_back(x);
		s.insert(x);
	}
	for(ll i=0;i<min(n,sz(v));i++)
		res+=v[i];
	if(n>sz(v)){
		res=0;
		for(ll i=0;i<sz(v);i++){
			if(x==v[i]){
				n-=i;
				ll sum=0;
				for(ll j=i;j<sz(v);j++)
					sum+=v[j];
				res+=(n/(sz(v)-i))*sum;
				n%=(sz(v)-i);
				for(ll j=i;j<n+i;j++)
					res+=v[j];
				break;
			}
			res+=v[i];
		}
	}
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
    for(ll i=1;i<=qc;i++){
        solve();
    }
    debug("Total Time:%.4Lf\n",(ld)(clock()-z)/CLOCKS_PER_SEC);
}
