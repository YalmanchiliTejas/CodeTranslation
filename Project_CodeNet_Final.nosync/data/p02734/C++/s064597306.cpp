#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
const double eps = 1e-6;



/////////////////////////////////////////////

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

////////////////////////////////

//#define int long long
const int mod = 998244353;
const int N = 3001;
int dp[N][N];
void solve(){

	int n , s;
	cin>>n>>s;
	int a[n];
	for(int i = 0; i < n ; ++i)
		cin>>a[i];

	for(int i = 0 ; i < n ; ++i){

		if(i==0){
			dp[i][a[i]] = i+1;
			continue;
		}
		dp[i][a[i]] = i+1;
		for(int sum = s; sum >= 0 ; --sum){

			if(sum - a[i] > 0){
				dp[i][sum] += dp[i-1][sum - a[i]];
			}
			else break;
			if(dp[i][sum]>=mod)
				dp[i][sum]-=mod;
		}
		for(int sum = s; sum >= 0 ; --sum){

			dp[i][sum]+=dp[i-1][sum];

			if(dp[i][sum] >= mod)
				dp[i][sum]-=mod;
		}
	}
	long long ans = 0;
	for(int i = 0 ; i < n ; ++i){

		if(i==0){

			if(dp[i][s])
				ans = n - i + 1;
			continue;
		}

		long long val = dp[i][s] - dp[i-1][s];
		val += 5LL*mod;
		val%=mod;
		val*=(n-i);
		val%=mod;
		ans += val;
		ans%=mod;
	}

	// for(int i = 0 ; i < n ; ++i){

	// 	for(int j = 0 ;j <= s; ++j)
	// 		cout<<dp[i][j]<<" \n"[j==s];
	// }

	cout<<ans<<endl;


}

signed main(){

    fast;
    int t = 1;
    //cin>>t;
    for(int i = 1 ; i <= t ; ++i){

    	solve();
    }
}




