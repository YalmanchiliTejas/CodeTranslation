#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x.begin(),x.end())
#define pii pair<int,int> 
#define vi vector<int> 
#define FOR(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define fi first
#define se second
using namespace std;
void solve()
{
 int n;
 cin>>n;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 {
 	cin>>v[i];
 }	
 vector<int> pref(n);
 pref[n-1]=v[n-1]%MOD;
 for(int i=n-2;i>=0;i--)
 pref[i]=(pref[i+1]%MOD+v[i]%MOD)%MOD;
 int sum=0;
 for(int i=0;i<n-1;i++)
 sum=(sum%MOD+(v[i]%MOD)*(pref[i+1]%MOD))%MOD;
 cout<<sum%MOD<<endl;
}
int32_t main()
{
	int t=1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

