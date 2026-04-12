#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
// Policy based data structure 
typedef tree<int, null_type, 
			less_equal<int>, rb_tree_tag, 
			tree_order_statistics_node_update> 
	indexed_set;  
#define ll long long int
#define pii pair<ll,ll>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define vi vector<ll>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdin); fflush(stdout);
#define F first
#define S second
#define np next_permutation
#define inf 1e18
#define mod 1000000007
#define N 200009
#define pi (double)2*acos(0.0)
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
void sout(){
	cout<<endl;
}
template <typename T,typename... Types>
void sout(T var1,Types... var2){
	cout<<var1<<" ";
	sout(var2...);
}
/*******************************************************************/



void solve(){
	ll n;
	cin>>n;
	ll a[n];
	rep(i,0,n)
		cin>>a[i];
	ll pre[n];
	pre[0]=a[0];
	rep(i,1,n){
		pre[i]=pre[i-1]+a[i];
		pre[i]%=mod;
	}
	ll ans=0;
	rep(i,1,n){
		ans=(ans+ (pre[i-1]*a[i])%mod)%mod;
	}
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}