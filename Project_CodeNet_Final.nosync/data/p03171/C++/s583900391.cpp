#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define sz size()

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1){cout<<name<<" : "<<arg1<<"\n";}
template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args)
{const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" , ";__f(comma+1, args...);} 
#define traceloop(x,a) { cerr<<#a<<": "; for(ll ix=0;ix<x;ix++) cerr<<a[ix]<<" "; cerr<<endl; }

int main()
{
	ios::sync_with_stdio(0);

	int n, i, j, m, k;
	cin>>n;
	int a[n];
	for(i=0;i<n;++i)
		cin>>a[i];

	ll dp[n][n];
	memset(dp, 0, sizeof dp);
	for(k=0;k<=n;++k)
	{
		for(i=0;i+k<n;++i)
		{
			j = i + k;
			//trace(i, j);
			if(i==j)
				dp[i][i] = a[i];
			else
				dp[i][j] = max(-dp[i+1][j] + a[i], -dp[i][j-1] + a[j]);
		}
	}

	cout << dp[0][n-1] << "\n";

	return 0;
}