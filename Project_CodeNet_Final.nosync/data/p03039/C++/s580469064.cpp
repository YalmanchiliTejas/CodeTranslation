#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)


const ll mod=1e9+7;
ll fp(ll a, ll b) {
	ll res=1;
	while(b) {
		if(b&1) res=(res*a)%mod;
		a=a*a%mod;
		b/=2;
	}
	return res;
}

int main() {
	IO;
	vector<ll> fact(200001, 1);
	for(int i=1;i<=200000;++i) {
		fact[i]=ll(i)*fact[i-1]%mod;
	}
	ll n,m,k;
	cin>>n>>m>>k;
	ll ways=fact[n*m-2]*fp(fact[k-2], mod-2)%mod*fp(fact[n*m-k], mod-2)%mod;
	
	ll sum_n=0;
	ll sum_m=0;
	for(ll i=1;i<m;++i) {
		sum_m+=i*(m-i)%mod;
		sum_m%=mod;
	}
	for(ll i=1;i<n;++i) {
		sum_n+=i*(n-i)%mod;
		sum_n%=mod;
	}
	ll ans=0;
	ans+=ways*(n*n)%mod*(sum_m)%mod;
	ans+=ways*(m*m)%mod*(sum_n)%mod;
	ans%=mod;
	cout<<(ans)<<"\n";
	
	return 0;
}
