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

const double PI=3.1415926535897932384626433832795;
const ll INF = 1LL<<62;
const ll MINF = -1LL<<62;

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

ll n;
ll t[200001];
ll dp[200001][4];
ll calc(ll i, ll extra) {
	if(i<0) return (extra==0?0:-1LL<<60);
	if(dp[i][extra]!=-1LL<<60) return dp[i][extra];
	ll ans=-1LL<<60;
	for(int j=0;j<=extra;++j) {
		ans=max(ans,calc(i-j-2,extra-j)+t[i]);
	}
	return dp[i][extra]=ans;
}
int main() {
	IO;
	for(int i=0;i<200001;++i) for(int j=0;j<4;++j) dp[i][j]=-1LL<<60;
	cin>>n;
	for(int i=0;i<n;++i) cin>>t[i];
	if(n%2==0) cout<<max(calc(n-2,0),calc(n-1,1))<<"\n";
	else cout<<max(calc(n-1,2),calc(n-2,1))<<"\n";
	return 0;
}
