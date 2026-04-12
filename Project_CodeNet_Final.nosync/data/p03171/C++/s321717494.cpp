#include <bits/stdc++.h>
using namespace std;
#define int                     long long int
#define ld                      long double
#define pb                      push_back
#define MOD                     1000000007
#define inf                     3e18
#define vi                      vector<int>
#define vld                     vector<ld>
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define fi                      first
#define se                      second
#define fastIO                  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << " "<< name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

void inp_out()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
	#endif
}

int dp[3004][3004];
int n;
vi a;
vi pre;

int cal(int l,int r)
{
	if(dp[l][r]!=-1)
		return dp[l][r];
	int &ans=dp[l][r];
	ans=0;
	if(l==r)
		return ans=a[l];
	ans = max(-cal(l+1,r) + a[l] + pre[r] - pre[l],-cal(l,r-1) + a[r] + pre[r-1] - (l>0?pre[l-1]:0));
	return ans;
}

int32_t main()
{
	fastIO
	//inp_out();
	memset(dp,-1,sizeof(dp));
	cin>>n;
	a=pre=vi(n);
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		pre[i]+=a[i];
		if(i>0)
			pre[i]+=pre[i-1];
	}

	cout<< 2 * cal(0,n-1) - pre[n-1];

	return 0;
}