#include <bits/stdc++.h>
using namespace std;

typedef long double ld;									// XD
#define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define ii pair <int,int>
#define mii map <int,int>
#define vi vector<int>
#define vii vector< ii >
#define F first
#define S second
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a; i>=b; --i)
#define sz(x) (int)((x).size())
#define mem(a,x) memset(a,x,sizeof(a))
const long double PI=3.141592653589793238462643383279502884197169399375105820974944;
inline void io(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int mod = 1e9 + 7;
const int inf = 3e16;
const int maxn = 1e5+5;

void solve(){
	int n; cin>>n;
	int sf[n+5] = {}, a[n];
	rep(i, 0, n) cin>>a[i];
	repd(i, n-1, 0){
		sf[i] = a[i] + sf[i+1];
		sf[i] = sf[i]%mod;
	}
	int ans = 0;
	rep(i, 0, n){
		ans = (ans + ((sf[i]-a[i]+mod)%mod)*(a[i]%mod))%mod;
	}
	cout<<ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0); //io();
    //cout<<setprecision(12);
    int tc=1;// cin>>tc;
    while(tc--){
        solve();cout<<'\n';
    }
    return 0;
}
