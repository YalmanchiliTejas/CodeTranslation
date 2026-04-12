#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define sz(a) (ll)(a.size())
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(998244353)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll a,ll b){if(!b)return a;else return gcd(b,a%b);}
int main()
{
	ll n,x,m;
	cin>>n>>x>>m;
	map<ll,int>vis;
	deque<ll>cycle;
	ll sum = 0;
	ll ans = 0;
	while(true){
		x%=m;
		vis[x]++;
		if(vis[x] > 1)break;
		cycle.pb(x);
		sum+=x;
		x*=x;
		x%=m;
	}
	while(n && vis[cycle.front()] == 1){
		ans+=cycle.front();
		sum-=cycle.front();
		cycle.pop_front();
		n--;
	}
	if(vis[0]){
		while(n && !cycle.empty()){
			ans+=cycle.front();
			cycle.pop_front();
			n--;
		}
		cout<<ans;
	}else{
	    if(!n){cout<<ans;return 0;}
		ll j = sz(cycle);
		ll r = n/j;
		ll q = n%j;
		ans+=r*sum;
		for(int i=0;i<q;i++)ans+=cycle[i];
		cout<<ans<<'\n';
	}
}
