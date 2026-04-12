#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define dofloat cout<<fixed<<setprecision(8)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define bitcount __builtin_popcount
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin(),vec.rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vll;
typedef vector<pair<int,int> > vii;
typedef vector<int> vi;
typedef pair<int,int> ii;
const long long MOD=1000000007;
const long long MAX=100005;
const long double PI=3.14159265359;
const long double G=9.807;
const long long INF=1e18;
const long double EPS=1e-6;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
bool isprime(ll a){
  if(a==2)return 1;
  if(!(a&1))return 0;
  for(ll i=3;i*i<=a;i+=2)
    if(a%i==0)return 0;
  return 1;
}
ll mpow(ll base,ll exponent,ll modulus){
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
ll minv(ll a,ll mod){
  ll _gcd=gcd(a,mod);
  assert(_gcd==1);
  return mpow(a,mod-2,mod);
}


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
ll ans;
vll a;
ll ST[4*MAX],A[MAX],dp[MAX];
ll vis[MAX];
void build(ll node,ll lo,ll hi){
	if(lo == hi){
		ST[node] = lo;
		return;
	}
	ll mid = (lo+hi)>>1;
	build(node<<1,lo,mid);
	build(node<<1|1,mid+1,hi);
	ST[node]=(A[ST[node<<1]]>A[ST[node<<1|1]])?ST[node<<1]:ST[node<<1|1];
}

void update(ll node,ll lo,ll hi,ll x,ll y){
	if(lo == hi){
		ST[node]=lo;
		A[lo]+=y;
		return;
	}
	ll mid = (lo+hi)>>1;
	if(lo<=x and mid>=x){
		update(node<<1,lo,mid,x,y);
	}
	else{
		update(node<<1|1,mid+1,hi,x,y);
	}
	ST[node]=(A[ST[node<<1]]>A[ST[node<<1|1]])?ST[node<<1]:ST[node<<1|1];
}

ll query(ll node,ll lo,ll hi,ll l,ll r){
	if(lo>r or hi<l){
		return -1;
	}
	else if(l<=lo and hi<=r){
		return ST[node];
	}
	ll mid = (lo+hi)>>1LL;
	ll p1 = query(node<<1,lo,mid,l,r);
	ll p2 = query(node<<1|1,mid+1,hi,l,r);
	if(p1 == -1)return p2;
	if(p2 == -1)return p1;
	return (A[p1]>A[p2])?p1:p2;
}
int main(){FAST;
multiset<ll>f;
cin>>n;
ll x;
cin>>x;
f.insert(x);
for(ll i=1;i<n;i++){
	cin>>x;
	auto it = f.lower_bound(x);
	if(it == f.begin()){
		f.insert(x);
	}
	else{
		it--;
		f.erase(it);
		f.insert(x);
	}
}
cout<<f.size();
return 0;
}