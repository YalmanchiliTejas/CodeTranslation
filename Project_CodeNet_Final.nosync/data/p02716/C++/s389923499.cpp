#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
int powmod(int a,int l, int md){a%=md; int res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
int binpow(int a,int l){int res=1;while(l){if(l&1)res=res*a;l/=2;a=a*a;}return res;}
int invmod(int a, int md){return powmod(a,md-2,md);}
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef vector<int> vi; typedef pair<int, int> ii; typedef vector< ii > vii;
#define pb push_back
int __set(int b, int i) {return b|(1LL<<i);} //set ith bit
int __unset(int b, int i) {return b&(~(1UL<<i));}
int __check(int b, int i) {return b&(1LL<<i);} //returns 0 if ith bit is 0
int mulmod(int a, int b, int md) {return (((a%md)*(b%md))%md+md)%md;}
int addmod(int a, int b, int md) {return ((a%md+b%md)%md+md)%md;}
int submod(int a, int b, int md) {return (((a%md-b%md)%md)+md)%md;}
int divmod(int a, int b, int md) {return mulmod(a, powmod(b, md-2, md), md);} //if md is prime;
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
priority_queue<int, vector<int>, greater<int> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve1(vi& a, int n) {
	int dp[n][3];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++)
			dp[i][j]=-inf;
	}
	int s=0;
	for(int i =1; i < n; i+=2) {
		s+=a[i];
	}
	dp[0][1]=a[0];
	for(int i = 2; i < n; i++) {
		if(i-3>=0) {
			dp[i][2]=max(dp[i][2],dp[i-3][1]+a[i]);
		}
		dp[i][2]=max(dp[i][2],dp[i-2][2]+a[i]);
		dp[i][1]=max(dp[i][1],dp[i-2][1]+a[i]);
	}
	return max({s,dp[n-2][1],dp[n-1][2]});
}
int solve2(vi& a, int n) {
	int dp[n][5][3];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 5; j++) {
			for(int k = 0; k < 3; k++)
				dp[i][j][k]=-inf;
		}
	}
	dp[0][1][0]=a[0];
	for(int i = 2; i < n; i++) {
		dp[i][1][0]=max(dp[i][1][0],dp[i-2][1][0]+a[i]);
		dp[i][2][1]=max(dp[i][2][1],dp[i-2][2][1]+a[i]);
		dp[i][2][2]=max(dp[i][2][2],dp[i-2][2][2]+a[i]);
		dp[i][3][1]=max(dp[i][3][1],dp[i-2][3][1]+a[i]);
		if(i-3>=0) {
			dp[i][2][1]=max(dp[i][2][1],dp[i-3][1][0]+a[i]);
			dp[i][2][2]=max(dp[i][2][2],dp[i-3][2][1]+a[i]);
		}
		if(i-4>=0) {
			dp[i][3][1]=max(dp[i][3][1],dp[i-4][1][0]+a[i]);
		}
	}
	int mx=-inf;
	if(n>=3) mx=dp[n-3][1][0];
	return max({mx,dp[n-1][2][2],dp[n-2][2][1],dp[n-1][3][1]});
}
signed main(void)
{
	IOS;
	int n; cin>>n;
	vi a(n);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	if(n%2==0) {
		cout<<solve1(a,n)<<endl;
	} else {
		vi a1;
		for(int i  =1;i  <n; i++)
			a1.pb(a[i]);
		cout<<max(solve2(a,n),solve1(a1,n-1))<<endl;
	}
	return 0;
}