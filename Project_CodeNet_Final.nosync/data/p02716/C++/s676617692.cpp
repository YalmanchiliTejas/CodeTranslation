#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; 
using namespace std;
#define int long long
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mll map<ll,ll>
#define mii map<int,int>
#define mp make_pair
#define pb push_back
#define rep(i,b) for(ll (i)=0;i<(b);i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define CLR(p) memset(p, 0, sizeof(p))
#define SET(p) memset(p, -1, sizeof(p))
#define DEBUG true
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
//typedef long long int ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> new_data_set; 
const int MAX=200005;
#define MOD 1000000007
/*std::cout << std::fixed;
std::cout << std::setprecision(6);*/
//(a%mod-b%mod+mod)%mod



/************************************


 
*************************************/

vector<vector<ll>>v;
ll T=0;
ll cnt1=0,cnt0=0;
vector<ll>dep;
bool visited[MAX];
vector<ll>par;
vector<ll>tin,tout;
vector<ll>col;
ll f=0,k=1;
map<pll,ll>m;
ll dp1[MAX],dp2[MAX];
ll red,blue;
ll ans;
ll dp[MAX];

ll lca(ll u,ll v){
	while(u!=v){
		ll l1,l2;
		l1 = log2(u);
		l2 = log2(v);
		//cout<<l1<<"$$"<<l2<<endl;
		if(l1<l2)
			swap(u,v);
		u /=2;
	}
	return u;
}





signed main(){
	boost;
	int t=1;
	// cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		rep(i,n)
			cin>>a[i+1];
		int dp[n+1];
		CLR(dp);
		int prefix[n];
		CLR(prefix);
		prefix[1]=a[1];
		for(int i=3;i<=n;i+=2){
			prefix[i]=prefix[i-2]+a[i];
		}
		dp[1]=a[1];

		for(int i=2;i<=n;i++){
			if(i==3){
				dp[i] = max(dp[i-1],a[i]);
				continue;
			}
			if(i%2==0){
				dp[i] = max(prefix[i-1],dp[i-2]+a[i]);
			}
			else{
				dp[i] = max(dp[i-1],dp[i-2]+a[i]);
			}
		}
		cout<<dp[n]<<endl;
	}

	return 0;
}