#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file 
//#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
#define pb push_back
#define ff first
#define ss second
#define ii insert
#define ld long double
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define ppb pop_back
#define nuenxfiu ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define input freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define TT int testcases;cin>>testcases;while(testcases--)
#define mk make_pair
#define MAX ((int)2e9+17)
#define mod ((int)1e9+7)
#define MOD 1000003
//int fact[1000007]={0};
//upper_bound is maximum index of an array element not greater than the given one
//lower bound is minimum index of an array element not less than the given one

#define N (int)1e6+10
int fpow(int n, int k, int p = mod) {int r = 1; while(k > 0) {if (k & 1) r = r * n%p; n = n * n%p; k = k >> 1;} return r;}
int expo(int x,int y){ int res=1; while(y) {if(y%2) res=(res*x%mod)%mod; x=(x*x)%mod; y/=2; } return res;}
int sub(int a, int b) {return (a%mod - b%mod + mod)%mod;}
int mul(int a, int b) {return ((a%mod)*(b%mod) + mod)%mod;}
int inv(int x) {return expo(x, mod-2);}
#define endl "\n";
using namespace std;


void solve()
{	
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	b[i]=a[i];
	}
	
	for(int i=n-2;i>=1;i--)
	{
		a[i]=a[i]+a[i+1];
	}
	
	int ans=0;
	
	for(int i=1;i<n;i++)
	{
		int q=mul(a[i],b[i-1]);
		ans=(q%mod+ans%mod)%mod;
	}
	cout<<ans<<endl;
}


signed main()
{
    
	nuenxfiu
	int t;
	//cin>>t;
	t=1;
	for(int i=1;i<=t;i++)
	{
	//cout<<"Case #"<<i<<": ";
	solve();
	}
     return 0;
}