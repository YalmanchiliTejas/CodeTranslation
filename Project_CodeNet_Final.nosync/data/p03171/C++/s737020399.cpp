#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std; 
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;
 
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define F0Rd(i,a) for (int i = a - 1; i >=0 ; i--)
#define FORd(i,a,b) for (int i = b - 1; i >= a; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define newl '\n'
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define print(x) cout << x << newl;
#define finish(x) return cout << x << "\n", 0;
#define bug(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " " << 
 
const int MXN = 2e5 + 5;
//const int MXN = 1e6 + 5;
const ll MOD = 998244353;
const ll INF = 1e9 + 7;
 

int N;
ll a[3005], DP[3005][3005];

ll dp(int l, int r){
    if (l > r) return 0;
    if (DP[l][r] != -1e18) return DP[l][r];
    if (l == r) return DP[l][r] = a[l];
    if (r - l == 1) return DP[l][r] = abs(a[r]-a[l]);
    return DP[l][r] = max(a[r]-dp(l,r-1),a[l]-dp(l+1,r));
}
 
int main(){ FAST
    //ifstream cin("/Users/konwoo/input.txt");
    //ofstream cout("/Users/konwoo/output.txt");

    cin >> N;
    F0R(i,N) cin >> a[i];
    F0R(i,N) F0R(j,N) DP[i][j] = -1e18;
    finish(dp(0,N-1));
 

    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    return 0;
}
