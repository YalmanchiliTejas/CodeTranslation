#pragma GCC optimize ("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ts to_string
#define ub upper_bound
#define lb lower_bound
const char nl = '\n';
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using str = string;
//The following debugging code was taken from Benjamin Qi's template :) 
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
    stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
    str res = "{"; for(int i = 0;i < (int)v.size(); i++) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; for(int i = 0; i < b.size(); i++) res += char('0'+b[i]);
    return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { 
    bool fst = 1; str res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += ts(x);
    }
    res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
    return "("+ts(p.f)+", "+ts(p.s)+")"; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << ts(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }

#ifdef LOCAL 
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif
//CODE STARTS HERE-----------------------------------------------------------------------------------------// 
const int N = 3001;
int n; ll a[N], dp[N][N][2];
ll solve(int l, int r, int t){
    dbg(l, r, t);
    if(dp[l][r][t] != -1)
        return dp[l][r][t];
    if(r == l){
        return dp[l][r][t] = a[r]*(t==0?1:-1);
    }
    if(t == 0){
        dp[l][r][t] = max(solve(l, r-1, t^1)+a[r], solve(l+1, r, t^1)+a[l]);
        dbg(dp[l][r][t],l,r,t);
        return dp[l][r][t];
    }
    else{
        dp[l][r][t] = min(solve(l, r-1, t^1)-a[r], solve(l+1, r, t^1)-a[l]);
        dbg(dp[l][r][t],l,r,t);
        return dp[l][r][t];
    }
}
signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(0, n-1, 0) << nl;
}