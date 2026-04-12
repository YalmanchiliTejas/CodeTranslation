#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=b-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define MOD 1000000007
#define MAXN 52
#define MAXH 20
#define MAXM 52
#define INF 100000000
#define ll long long
#define ull unsigned long long
#define RNG rng mt19937(time(NULL))
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
#define vec vector
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll dp[10000][100],dp2[10000][100];

int main(){
	fast_io();
	string s;
	int d;
	cin >> s >> d;
	int n = s.length();
	cu(i,0,10)dp[0][i % d] += 1;
	cu(i,1,10000){
		cu(j,0,10){
			int add = j;
			cu(k,0,100){
				dp[i][(k + add) % d] += dp[i-1][k];
				dp[i][(k + add) % d] %= MOD;
			}
		}
	}
	fu(i,0,s[n-1] - '0')dp2[0][i % d] += 1;
	cu(i,1,n){
		cu(j,0,s[n - i - 1] - '0'){
			int add = j;
			cu(k,0,100){
				dp2[i][(k + add) % d] += dp[i-1][k];
				dp2[i][(k + add) % d] %= MOD; 
			}
		}
		int add = (s[n - i - 1] - '0');
		cu(k,0,100){
			dp2[i][(k + add) % d] += dp2[i-1][k];
			dp2[i][(k + add) % d] %= MOD; 
		}
	}
	cout << (dp2[n-1][0] + MOD - 1) % MOD << '\n';
}
