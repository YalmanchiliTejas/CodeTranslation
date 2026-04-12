#include<bits/stdc++.h>
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
#define mx 200000
using namespace std;
ll mi(ll n,ll m){ll pw=n%m;ll ex=m-2;ll ans=1;while(ex){if(ex&1) ans = ans*pw%m;pw = pw*pw%m;ex>>=1;}return ans%mod;}
ll pw(ll a,ll n){ll pw=a%mod;ll ex=n;ll ans=1;while(ex){if(ex&1) ans = ans*pw%mod;pw = pw*pw%mod;ex>>=1;}return ans%mod;}
template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }
void show(ll x){cout<<x<<" ";}
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
//#define d double
void solve(){
	string str;
	cin>>str;
	ll d;cin>>d;
	ll n=str.length();
	vector<vector<ll>> dp(d,vector<ll>(2));
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		vvl tdp(d,vl(2));
		int v=str[i]-'0';
		for(int rk=0;rk<d;rk++){
			for(bool is_smaller:{true,false}){
				for(int k=0;k<=9;k++){
					if(k>v && !is_smaller) break;
					tdp[(rk+k)%d][is_smaller||k<v]=(tdp[(rk+k)%d][is_smaller||k<v]+dp[rk][is_smaller])%mod;
				}
			}
		}
		dp=tdp;
	}
	cout<<(dp[0][0]+dp[0][1]-1+mod)%mod;
 
}
int32_t main(){
int t=1;
//cin>>t;
while(t--){
	solve();
}
}