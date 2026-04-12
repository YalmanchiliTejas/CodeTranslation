#include <bits/stdc++.h>
//Fast io
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//Class shorthands
#define ll long long
#define db long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int,int>
#define mii map<pii,int>
//Function Shorthands
#define fi first
#define se second
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair
#define po pop_back
#define eb emplace_back
//Code Shorthands
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repe(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=b;i>=a;i--)
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
//Constants
#define hell 1000000007
#define PI acos(-1.0)
using namespace std;

void solve(){
	ll n, x, m;
	cin>>n>>x>>m;
	ll cur = x;
	ll r = 1;
	vector<ll> v;
	v.pb(0ll);
	map<ll, ll> s;
	while(true){
		if(s.find(cur%m)!=s.end()) break;
		v.pb(cur);
		s[cur] = r++;
		cur = (cur*cur)%m;
	}
	ll l = s[cur];
	for(int i=1;i<v.size();i++){
		v[i] += v[i-1];
	}
	if(n<v.size()){
		cout<<v[n]<<endl;
	}
	else{
		ll ans = v[l-1];
		n-=(l-1);
		ll sz = v.size();
		ans += (v[sz-1]-v[l-1])*(n/(sz-l));
		ans += v[l -1 + n%(sz-l)] - v[l-1];
		cout<<ans<<endl;
	}
}

int main(){
	io;
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}