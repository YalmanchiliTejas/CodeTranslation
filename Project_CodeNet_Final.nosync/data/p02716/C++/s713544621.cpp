#include <bits/stdc++.h>

#include <set>
#include <iterator>
using namespace std;
// using namespace __gnu_pbds;


#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define INF (ll)1e17
#define matrix vector<vector<ll> >

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ASST(x, l, r) assert( x <= r && x >= l )
#define maxbits 9
#define maxmask (1ll<<maxbits)
// typedef tree<pll, null_type, less<pll>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
const int  N=1e6 +10, M=(ll)1e9+1 ;
const int mod =998244353 ,sz=5, MAX=(ll)1e6+10;
string fir="Monocarp",sec="Bicarp";


ll maxi(ll a,ll b,ll c,ll d){
	return max(a,max(b,max(c,d)));
}

void work(){
	ll n;
	cin >> n;

	vl a(n+1);
	for(ll i=1;i<=n;i++)
		cin >> a[i];

	ll dp[n+1][2];
	memset(dp,0,sizeof(dp));

	dp[2][0]=a[1];
	dp[2][1]=a[2];
	for(ll i=3;i<=n;i++){
		if(i&1){
			dp[i][1]=max({dp[i-2][1],dp[i-3][1],dp[i-2][0],dp[i-3][0]})+a[i];
			dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
		}
		else{
			dp[i][1]=max({dp[i-2][1],dp[i-2][0],dp[i-1][0]})+a[i];
			dp[i][0]=dp[i-2][0]+a[i-1];
		}
	}

	cout << max(dp[n][0],dp[n][1]) ;
}

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);

	
	// precomp();
	ll t;
	// cin >> t;
	t=1;
	while(t--){
	        work();
	
	}
return 0;
}
	