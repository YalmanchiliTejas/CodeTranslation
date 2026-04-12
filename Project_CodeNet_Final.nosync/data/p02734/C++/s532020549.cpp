/*author : Yashvardhan
Wednesday, April 08, 2020
5:41 PM
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define int ll
#define pb push_back
#define vi vector<int>
#define pi pair<int,int>
#define vpi vector<pi>
#define ff first
#define ss second
#define mp make_pair
#define endl '\n'
#define all(a) a.begin(), a.end()
#define initialise(a, x) memset(a, x, sizeof(a))
#define rev(Y) reverse(all(Y))
#define printArr(name,from,to) for(int x = from; x < to; x++) cout << name[x] << " ";


#pragma GCC optimize ("O3")
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

const int mod = 998244353;
const int inf = 2e18;
const int ninf = -2e18;

int takemod(int a){return ((a%mod)+mod)%mod;}

int pow(int a, int b, int m)
{
	int ans = 1;
	a %= m;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % m;
		b /= 2;
		a = (a * a) % m;
	}
	return ans;
}

int modinv(int a){return takemod( pow( takemod(a), mod-2,mod ) );}

const int MX = 3005;
int dp[MX][MX];
int pref[MX][MX];

signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	#ifdef __APPLE__
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#endif

	time_t t1, t2;
	t1 = clock();
	
	int n,s;
	cin >> n >> s;

	vi arr(n + 1);
	for(int i = 1; i <= n; i++) cin >> arr[i];

	for(int i = 1; i <= n; i++){
		dp[i][arr[i]] = i;
		for(int j = arr[i]; j <= s; j++){
			dp[i][j] = (dp[i][j]%mod + pref[i-1][j - arr[i]]%mod)%mod;
		}

		for(int j = 1; j <= s; j++){
			pref[i][j] = (dp[i][j]%mod + pref[i-1][j]%mod)%mod;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = (ans % mod + (( dp[i][s]% mod )*(n - i + 1) % mod) % mod) % mod;
	}
	
	cout << ans << endl;

	t2 = clock();
	cerr << endl << t2-t1 << endl;
	
	return 0;
}

