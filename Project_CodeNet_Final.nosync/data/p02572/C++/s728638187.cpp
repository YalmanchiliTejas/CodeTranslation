#include <bits/stdc++.h>
using namespace std;

#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define ll                long long
#define mod               1000000007
#define fr                first
#define sc                second
#define vl                vector<ll>
#define pll               pair<ll,ll>
#define u_map             unordered_map<ll,ll>

#define pi                3.141592653589793
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define printV(v) for(auto itr:v) cout<<itr<<" "; cout<<endl;
#define printA(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define printC cout<<"yes"<<endl;
#define printVP(v) for(auto itr:v) cout<<itr.fr<<" "<<itr.sc<<endl;
#define cinarr(a,n) for(int i=0; i<n; i++) cin>>a[i];



void solve(){
	ll n; cin>>n;
	vl a(n); cinarr(a,n);
	
	vl preb(n,0); preb[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--) preb[i]=preb[i+1]+a[i];
	
	ll ans=0;
	for(int i=0;i<n-1;i++) 
		ans=   ( ans+ (   (preb[i+1])%mod  * a[i]  )%mod ) %mod ;
	cout<<ans<<endl;
}



signed main(){
    ios;
	int testcases=1;
	//cin >> testcases;

	while(testcases--){
	    solve();
	}

	return 0;
}
