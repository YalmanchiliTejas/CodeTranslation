// INCLUDES
#include <bits/stdc++.h>
#include<assert.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
//DEFINES
#define MAX 1000001
#define pii pair<int, int>
#define c1 __builtin_popcount
#define F first
#define S second
#define all(s) begin(s),end(s)
#define MIN3POS(a, b, c) (a) =< (b) ? ((a) =< (c) ? 1 : 3) : ((b) =< (c) ? 2 : 3)
#define MAX3POS(a,b,c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2:3)
#define endl '\n'
#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define IOS   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);}
//NAMESPACES
using namespace __gnu_pbds; 
using namespace std;
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
int n;
vector<int> v;
int dp[3001][3001][2];
int func(int i,int j,int t) {
    if(i == j) return t==0 ? v[i]: -v[i];
    if(i>j) return 0;
    int ans = 0;
    int &res = dp[i][j][t];
    if(res == -1e15) {
    if(t == 0) {
         ans  = max(v[i] + func(i+1,j,1), v[j] + func(i,j-1,1));
    } else if(t == 1) {
        ans = min(func(i+1,j,0)-v[i],func(i,j-1,0)-v[j]);
    }
    res = ans;
    }
    return res;
    // debug(i,j,ans,t);
    return ans;
}
void solve(){
    cin>>n;
    v.resize(n);
    FOR(i,0,n) cin>>v[i];
    FOR(i,0,3001) FOR(j,0,3001) dp[i][j][0]=-1e15,dp[i][j][1] = -1e15;
    int ans = func(0,n-1,0);
    cout<<ans;
}
int32_t main()
{
IOS
int t=1;
// cin>>t;
while(t--) {
    solve();
}
return 0;
}
// Use emplace back in place of pushback
// Use tie function , for object destructuring