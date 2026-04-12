#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define N 100005
#define mod 998244353 
#define boost ios_base::sync_with_stdio(false);cin.tie(0)
#define prec(n) fixed<<setprecision(n)

#define mii unordered_map<int,int>
#define mll unordered_map<ll,ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi  first

#define se second
#define pb push_backP
#define mp make_pair
#define pp pop_back
#define vii vector<int>
#define vll vector<ll>
#define vpp vector<pii>
#define all(c) c.begin(),c.end()
#define tr(it,c) for(it = c.begin() ; it!=c.end() ; it++)
int inf = INT_MAX ;
ll modulo(ll num,ll MOD=mod){ return ((num%MOD)+MOD)%MOD;} // for negative integer
ll power(ll b,ll e,ll MOD=mod){ll ans=1; while(e){if(e%2) ans=(ans*b)%MOD; b=(b*b)%MOD; e/=2;} return ans;}
ll inv(ll num,ll MOD=mod){ return power(modulo(num),MOD-2,MOD); }
ll gcd(ll a,ll b){ return ((b==0) ? a:gcd(b,a%b));}

int main(){
	boost;

	int a,b;
	cin>>a>>b;

	if(a==b){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}