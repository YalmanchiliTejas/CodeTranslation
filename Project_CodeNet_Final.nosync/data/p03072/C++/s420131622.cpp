#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define dofloat cout<<fixed<<setprecision(8)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define bitcount _builtin_popcount
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin(),vec.rend()
using namespace __gnu_pbds;
using namespace std;
//typedef
typedef long long ll;
typedef long double ld;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vll;
typedef vector<pair<int,int> > vii;
typedef vector<int> vi;
typedef pair<int,int> ii;
//constants
const long long MOD=1000000007;
const long long MAX=100005;
const long double PI=3.14159265359;
const long double G=9.807;
const long long INF=1e18;
const long double EPS=1e-6;
//
#define forn(i, n)for(ll i=0;i<n;i++)
// gcd of a and b
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
// distance between (a,b) and (c,d)
long double dis(long long a,long long b,long long c,long long d){return sqrt( ((a)-(c))*((a)-(c))+((b)-(d))*((b)-(d)) );}
// simple prime check
bool isprime(long long a){
if(a==2)return 1;
if(!(a&1))return 0;
for(ll i=3;i*i<=a;i+=2){
	if(a%i==0)return 0;
}
return 1;
}
// fast expo
long long mpow(long long base,long long exponent,long long modulus){
if(modulus==1)return 0;
long long result = 1;
base=base%modulus;
while(exponent){
		if(exponent%2 == 1)
			result=(result*base)%modulus;
		exponent=exponent>>1;
		base=(base*base)%modulus;
	}
return result;
}
// modular inverse
ll minv(ll a,ll mod){
	ll _gcd=gcd(a,mod);
	assert(_gcd==1);
	return mpow(a,mod-2,mod);
}

/*
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

/*
ll dx[]={1,0,-1,0,1,1,-1,-1};
ll dy[]={0,-1,0,1,1,-1,-1,1};
*/

/*
void sieve(int N){
	for(int i=0;i<=N;i++){
		spf[i]=i;
	}
	for(int i=2;i*i<=N;i++){
		if(spf[i]==i){
			for(ll j=i*i;j<=N;j+=i){
				spf[j]=min(spf[j],i);
			}
		}
	}
	return;
}
*/

/*
void nCr(ll n,ll k){
	ll i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=min(i,k);j++){

			if(j==0 or j==i)C[i][j]=1LL;
			else  C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;

		}
	}
	return;
}
*/
/*
ll ncr(ll N,ll K){
	if(N<K)return 0;
	if(K==0)return 1;
	if(N==0)return 0;

	ll den=1;
	for(ll i=1;i<=K;i++)den*=i;
	ll num=1;
	while(K--){
		num*=N;
		if(num%den==0){
			num/=den;
			den=1;
		}
		N--;
	}

	return num;
}
*/
ll n;
ll pre[25],a[25];
int main(){FAST;
cin>>n;
for(ll i=0;i<n;i++){
	cin>>a[i];
	if(i){
		pre[i]=max(pre[i-1],a[i]);	
	}
	else{
		pre[i]=a[i];
	}
}
ll ans=1;
for(ll i=1;i<n;i++){
	if(pre[i-1]<=a[i]){
		ans++;
	}
}
cout<<ans;
return 0;
}


