#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI 3.141592653589793238462643383279502884L
#define make_unique(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define Sort(vec) sort(vec.begin(),vec.end())
#define RSort(vec) sort(vec.rbegin(),vec.rend())
#define endl "\n"
#define tr1(i) cout<<i<<endl;
#define tr2(i,j) cout<<i<<" "<<j<<endl;
#define tr3(i,j,k) cout<<i<<" "<<j<<" "<<k<<endl;
#define vvi vector<vector<int> > 
#define vvl vector<vector<ll> >
#define all(st) st.begin(),st.end()
#define vpl vector<pair<ll,ll> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define pl pair<ll,ll>
#define al vector<list<int> >
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repit(st) for(auto it=st.begin();it!=st.end();it++)
#define ull unsigned long long int
#define eb emplace_back
#define pb push_back
#define ll long long int
#define minf -(1e18)
#define inf 1e18
#define f first
#define se second
#define mod 1000000007
using namespace std;
using namespace __gnu_pbds; 
ll mi(ll n,ll m){ll pw=n%m;ll ex=m-2;ll ans=1;while(ex){if(ex&1) ans = ans*pw%m;pw = pw*pw%m;ex>>=1;}return ans%mod;}
ll pw(ll a,ll n){ll pw=a;ll ex=n;ll ans=1;while(ex){if(ex&1) ans = ans*pw;pw = pw*pw;ex>>=1;}return ans;}
ll pwm(ll a,ll n){ll pw=a%mod;ll ex=n;ll ans=1;while(ex){if(ex&1) ans = ans*pw%mod;pw = pw*pw%mod;ex>>=1;}return ans%mod;}
template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }
template<typename T> using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//st.order_of_key(num)->number of elements < num
//st.find_by_order(i)->iterator of ith element in sorted order starting from zero
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll Abs(ll x){return x>0?x:(-x);}
ll Ceil(ll a,ll b){return a/b+(a%b!=0);}
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define mkp make_pair
//#define int long long int
//Binary_Search->dp->greedy
//auto check = [&](ll x){};
void solve(){
	int n;
	cin>>n;
	vl vec(n);
	cin>>vec;
	vl dp(n),pre(n);
	dp[0]=0;
	dp[1]=max(vec[0],vec[1]);
	pre[0]=vec[0];
	for(int i=2;i<n;i++){
		if(i&1) dp[i]=max(pre[i-1],vec[i]+dp[i-2]);
		else{
			dp[i]=max(dp[i-1],vec[i]+dp[i-2]);
			pre[i]=pre[i-2]+vec[i];
		}
	}
	cout<<dp[n-1]<<endl;
	
	
}
int main(){
int t=1;
//scanf("%d",&t);
while(t--){
	solve();
}
return 0;
}    
 