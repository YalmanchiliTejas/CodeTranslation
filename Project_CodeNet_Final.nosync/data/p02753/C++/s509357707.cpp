#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fit(x) for(auto it=x.begin();it!=x.end();++it)
#define se second
#define mp make_pair
#define ALP "abcdefghijklmnopqrstuvwxyz"
#define nline cout<<"\n"
#define rep(i,x) for(i=0;i<x;++i)
#define repr(i,a,b) for(i=a;i<=b;++i)
#define mi2 500000004
#define mi3 333333336
#define MOD 1000000007
#define N 1000005
#define pll pair<ll,ll>
#define Vll vector<ll>
#define W(t) while(t--)
#define modsum(a,b,M) (a%M + b%M)%M
#define modsub(a,b,M) (a%M - b%M + M)%M
#define modmul(a,b,M) (a%M * b%M)%M
#define moddiv(a,b,M) (a%M * modinv(b,M)%M)%M
using namespace std;
ll powermod(ll x,ll n,ll M)
{
	ll result=1;
	while(n>0)
	{
	  if(n % 2 ==1)
	    result=(result * x)%M;
	  x=(x*x)%M;
	  n=n/2;
	}
	return result;
}
vector<ll> readll() {
	cin>>ws;
	vector<ll> v;
	string input;
	getline(cin, input);
	cout<<input;
	istringstream is(input);
	ll num;
	while(is>>num) v.pb(num);
	return v;
}
ll modinv(ll n,ll p) {
	return powermod(n,p-2,p);
}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll fact[1000005],invf[1000005];
void facmod(ll n,ll M) {
	ll i;
	fact[0]=fact[1]=1;
	for(i=2;i<=n;++i) {
		fact[i]=((fact[i-1])%M * (i%M))%M;
	}
	invf[n]=modinv(fact[n],M);
	for (i=n-1;i>=0;--i){
		invf[i]=invf[i+1]*(i+1);
		invf[i]%=M;
	}
}
/*****
ll T=0;
ll p[200005], d[200005];
ll tin[200005], tout[200005];
vector<ll> g[200005];

void dfs(ll v, ll par = 1, ll dep = 0) {
	p[v] = par;
	d[v] = dep;
	tin[v] = T++;
	for (auto to : g[v]) {
		if (to == par) continue;
		dfs(to, v, dep + 1);
	}
	tout[v] = T++;
}
****/
void solve() {
	string s;
	int i,c=0;
	cin>>s;
	rep(i,3) {
		if(s[i]=='A') c++;
	}
	if(c==0 || c==3) cout<<"No";
	else cout<<"Yes";
}
int main() {
  	fastio;
	ll t=1;
	//cin>>t;
	W(t) {
		solve();
	}
	
  	return 0;
}