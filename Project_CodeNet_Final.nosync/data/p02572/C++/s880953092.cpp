#pragma GCC optimize(2)
#include<iostream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <cstring>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <map>
#include <unordered_map>
#include <vector> 
#include <bitset>
#include <cctype>
#include <set>
#include <stack>
#include <queue>
#include <fstream>
#include <numeric>
#include <random>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN = 200005;
const int MAXM = 20500;
const ll MOD = 1e9+7;

#define MP make_pair
#define INF 0x3f3f3f3f
#define closeSync ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template <typename T> inline T min(T a, T b, T c,T d) { return min(min(a, b), min(c,d)); }
template <typename T, typename T1> inline T qpower(T x, T p, T1 mod) { T re = 1; x %= mod; while (p) { if (p & 1)re = (re * x) % mod; x = (x * x) % mod; p >>= 1; }return re; }
#define mst(X,Y) memset(X,Y,sizeof(X)) 
#define rep(i, a, n) for (int i=(a); i<=(n); i++)
#define per(i, a, n) for (int i=(a); i>=(n); i--)
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) { cerr << " " << to_string(H);    debug_out(T...);}


// int solve(int l,int r)
// {
		
// }

ll a[MAXN];
ll sum[MAXN];
int main()
{//closeSync;
#ifdef DEBUG
	//freopen("C:/Users/86159/Desktop/input.txt", "r", stdin);
	//freopen("C:/Users/86159/Desktop/output.txt", "w", stdout);
#endif
	//clock_t c1 = clock();

	int n;
	cin>>n;
	rep (i,1,n)
		cin>>a[i];
	rep (i,1,n)
		sum[i] = (sum[i-1] + a[i])%MOD;
	ll ans = 0;
	rep (i,1,n-1)
	{// i + 1 -> n
		ans = (ans + a[i] * (sum[n] - sum[i] + MOD) % MOD) % MOD;
	}
	cout<<ans<<endl;
	//cerr << "Time:" << clock() - c1 << "ms" <<endl;
    return 0;
}