#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORit(it,a) for(auto it=a.begin();it!=a.end();it++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define vec vector
#define pb push_back
#define pop pop_back
#define all(x) x.begin(),x.end()
#define testcases ll t;cin>>t;while(t--)
#define mem(a,k) memset(a,k,sizeof(a))
#define F first
#define S second
#define MP(x,y) make_pair(x,y)
#define rt return
#define br break
#define ct continue
#define elif else if
#define ii pair<ll,ll>
#define arrin(a,n,index) for(int i=index;i<n;i++)cin>>a[i]
#define vecin(a,n,index) for(int i=index;i<n;i++)cin>>a[i]
#define arrout(a,n,index) for(int i=index;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define vecout(a,n,index) for(int i=index;i<n;i++)cout<<a[i]<<" ";cout<<endl;
ll mod = 1000000007;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	// START FROM HERE :)
	ll n;
	cin >> n;
	ll a[n];
	arrin(a, n, 0);
	ll sum[n];
	mem(sum, 0); sum[0] = a[0];
	FOR(i, 1, n) {
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 0;
	FOR(i, 0, n) {
		ans += (a[i] % mod * ((sum[n - 1] % mod - sum[i] % mod + mod) % mod)) % mod;
	}
	cout << ans % mod << endl;

}