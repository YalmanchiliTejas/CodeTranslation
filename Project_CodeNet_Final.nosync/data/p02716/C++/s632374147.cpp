#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
// #include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
//ios::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=6e5+7;
const double eps=1e-10;
// const ll mod=1e9+7;
#define STDIN freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);//************************************
#define Quick ios::sync_with_stdio(false);cin.tie(NULL);
#define int ll



// dp[i] = max(dp[i-2] + a[i], dp[i - 1]) // i&1 = 1

// dp[i] = max(dp[i-2] + a[i], dp[i-1])	//i & 1 = 0

const int N = 2e5 + 10;

ll presum[N];
int a[N];
ll dp[N];
signed main()
{
	//STDIN
	Quick
	int n;cin >> n;
	for (int i = 1; i <=n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) if (i&1) presum[i] += presum[i-1]+a[i]; else presum[i] += presum[i-1];
	dp[2] = max(a[1], a[2]);
	for (int i = 3; i <= n; i++)
	{
		if (i&1) dp[i] = max(dp[i-2] + a[i], dp[i-1]);
		else dp[i] = max(dp[i-2] + a[i], presum[i-1]);
	}
	cout << dp[n] << endl;
}