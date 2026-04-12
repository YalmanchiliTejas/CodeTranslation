
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sort(a) sort(all(a))
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define vll vector<ll>
#define pll pair<ll,ll>
// #define mod (ll)1e9+7
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define repf(i,a,b) for(i=a;i<b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define N 100005
int main()
{
	FAST
    int t=1;
    // cin>>t;
    ll mod=1000000007;
    while(t--)
    {
		int i,n;
		cin>>n;
		vll a(n+1,0);
		// a[0]=0;
		repf(i,1,n+1) cin>>a[i];
		ll b=0;
		ll ans=0;
		ans=ans+a[i]*b;
		repb(i,n,1)
		{
			// ans = (ans%mod+((a[i]%mod)*(b%mod))%mod)%mod;
			ans=(ans+((a[i]%mod)*(b%mod))%mod)%mod;
			// cout<<ans<<"\n";
			b+=a[i];
		}
		cout<<ans;
    }
    return 0;
} 
