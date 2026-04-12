/*author : Yashvardhan
Saturday, February 02, 2019
7:58 PM
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll
#define pb push_back
#define vi vector<int>
#define pi pair<int,int>
#define vpi vector<pi>
#define ff first
#define ss second
#define endl '\n'

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#ifdef __APPLE__
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif

template <typename T> ostream& operator << (ostream& os,const vector<T>& v){for(int i=0;i<v.size();++i) os<<v[i]<<" ";return os;} 
template <typename T> ostream& operator << (ostream& os,const set<T>& v){for(auto it:v) os<<it<<" ";return os;} 
template <typename T, typename S> ostream& operator << (ostream& os, const pair<T,S>& v) {os<<v.ff<<" "<<v.ss;return os;}

const int mod = 1e9 + 7;
const int inf = 2e18;
const int ninf = -2e18;

vi vals;
int dp[3005][3005];

int pow(int a, int b, int m)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % m;
		b /= 2;
		a = (a * a) % m;
	}
	return ans;
}

int solve(int start, int end){
	if(dp[start][end] != -1) return dp[start][end];
	if(start == end) return dp[start][end] = vals[start];
	if(start + 1 == end){
		return dp[start][end] = abs(vals[start] - vals[end]);
	}
	int op1 = vals[start] - solve(start+1,end);
	int op2 = vals[end] - solve(start,end-1);
	return dp[start][end] = max(op1,op2);
}

signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef __APPLE__
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#endif

	time_t t1, t2;
	t1 = clock();
	
	int n;
	cin>>n;

	for(int i = 1; i <= n ; i++){
		int x;
		cin>>x;
		vals.pb(x);
	}

	memset(dp,-1,sizeof(dp));
	
	solve(0,n-1);
	int ans = dp[0][n-1];
	cout<<ans<<endl;

	t2 = clock();
	cerr<<endl<<t2-t1<<endl;
	
	return 0;
}

