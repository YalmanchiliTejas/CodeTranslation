     //k_tourist
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define mx 3005
#define non __builtin_popcount
#define ml map<ll, ll> 
#define uml unordered_map<ll, ll>
#define ms map<string , ll> 
#define all(a) (a).begin(),(a).end()
#define ff first
#define ss second
#define pl pair<ll, ll>
#define vl vector<ll>
#define vll vector<pl>
#define tpl pair<ll, pl>
#define vlll vector<tpl>
#define vs vector<string>
#define pb push_back
#define mk make_pair
#define M_PI 3.14159265358979323846
#define endl '\n'
#define fst ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define inf ((ll)1e18 + 1)
#define bs binary_search
#define pq priority_queue
#define ub upper_bound
#define lb lower_bound
#define pow powr
#define sp(a) setprecision(a)
#define rep(i,a,b)  for (i=(a);i<(b);i++)
#define nrep(i,a,b) for (i=(a);i>(b);i--)
using namespace std;
using namespace __gnu_pbds;  

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>  ordered_set;
 
ll powr(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

void flag(ll fl){

	if(fl)
	cout<<"NO";
	else
	cout<<"YES";
}

ll a[mx], dp[mx][mx], n;

ll deq(ll x, ll  y){

	if(x <0 || y> n-1 || x> y)
	return 0;

	if(dp[x][y] != -1)
	return dp[x][y];

	return dp[x][y]= max(a[x] - deq(x+1, y), a[y] - deq(x, y-1));
}
void bta_de_yarr(){

	ll  i, j, fl=0, ans, m;

	cin>>n;

	rep(i, 0, n)
	cin>>a[i];

	rep(i, 0, n+1)
	rep(j, 0, n+1)
	dp[i][j]= -1;

	ans= deq(0 , n-1);
	
	cout<<ans;
	// flag(fl);
	cout<<endl;
}

int main(){
    fst

	// freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	ll t;
    t= 1;
	//cin>>t;
    while(t--){
        bta_de_yarr();
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 