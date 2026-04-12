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
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
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
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 51;
ll pat[N],sze[N];

ll rec(int lvl, ll x){
	if(x == 0)return 0;
	if(lvl == 0)return 1;
	if(x == 1)return 0;
	if(x <= 1 + sze[lvl-1])return rec(lvl-1,x-1);
	if(x == 1 + sze[lvl-1] + 1)return pat[lvl-1] + 1;
	if(x <= 1 + 2 * sze[lvl-1] + 1)return pat[lvl-1] + 1 + rec(lvl-1,x - 2 - sze[lvl-1]);
	else return 2 * pat[lvl-1] + 1;
}

int main(){
	ll n,x;
	cin >> n >> x;
	pat[0] = sze[0] = 1;
	fu(i,1,n){
		pat[i] = 2 * pat[i-1] + 1;
		sze[i] = 2 * sze[i-1] + 3;
	}
	cout << rec(n,x) << '\n';
}
