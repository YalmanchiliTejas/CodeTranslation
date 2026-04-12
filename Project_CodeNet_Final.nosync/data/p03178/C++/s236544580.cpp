#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;
using ll = long long;
using DBL = double;
using VI = vector<int>;
using VD = vector<DBL>;
using VVI = vector<VI>;
using VVD = vector<VD>;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i,n) FOR(i,0,n)
#define SZ(a) ((int)((a).size()))
#define ALL(x) (x).begin(), (x).end()
#define SET(a,v) memset((a), (v), sizeof(a))
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

//#define trace(...) {__f(#__VA_ARGS__, __VA_ARGS__);}
//template<typename Arg> void __f(const char* name, Arg&& arg) {
//  cerr << name << " = " << arg << std::endl;
//} template <typename Arg1, typename... Args>
//void __f(const char* names, Arg1&& arg1, Args&&... args) {
//  const char* comma = strchr(names + 1, ',');
//  cerr.write(names, comma - names) << " = " << arg1<<" | ";__f(comma+1, args...); }
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds; // OST: find_by_order, order_of_key
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//#pragma GCC optimize("Ofast")
//optimize("unroll-loops")
//target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///*** RNGS ***/
//SEED=chrono::steady_clock::now().time_since_epoch().count();
//// or high_resolution_clock
//mt19937 rng(SEED); /*or*/ random_device rd; mt19937 rng(rd());
//uniform_int_distribution<> dis(MIN, MAX);// usage: dis(rng)
//struct chash {int operator()(int x) const {return x^SEED;}};
//gp_hash_table<int,int,chash>m;//use cc if very less updates
///*** FAST IO ***/
//inline int scan(){ bool y=0; int x=0; char c=getchar_unlocked();
//while(c<'0'||c>'9'){ if(c=='-')y=1; c=getchar_unlocked();}
//while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar_unlocked();}
//return y?-x:x; }

const int MOD = 1000000007;
string k;
int d;
int dp[2][10010][128];

int calc(int pos, int rem, int lo) {
    if(pos == k.size()) return (rem == 0);
    int &y = dp[lo][pos][rem];
    if(y != -1) return y;
    y = 0;
    for(int i=0; i<=(lo?9:(k[pos]-'0')); ++i) {
        y += calc(pos+1, (rem+i)%d, (lo or (i < (k[pos]-'0'))));
        if(y >= MOD) y -= MOD;
    }
    return y;
}

int main() {
    #ifdef LOCAL_EXEC
//    freopen("sample.in", "r", stdin);
//    freopen("sample.out", "w", stdout);
    #else
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #endif
    memset(dp, -1, sizeof(dp));
    cin >> k >> d;
    cout << ((calc(0, 0, 0) == 0) ? (MOD - 1) : (calc(0, 0, 0) - 1)) << endl;
	return 0;
}
