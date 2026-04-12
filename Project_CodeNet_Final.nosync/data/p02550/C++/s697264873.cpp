#include <bits/stdc++.h>
using namespace std;
#pragma region
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
#define debug(x...) cerr << "[" << (#x) << "] = [", _print(x)
#else
#define debug(x...)
#endif
#pragma endregion
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(v) int((v).size())
#define int ll
#pragma region
#define x first
#define y second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#pragma endregion

void solve()
{
    int n, x, m;
    cin>>n>>x>>m;
    vector<int> r = {x%m};
    bitset<111'111> vst;
    vst[x%m] = 1;
    int st_val = -1;
    for (int i=1;;++i)
    {
        int now = r[i-1]*r[i-1]%m;

        if (vst[now])
        {
            st_val = now;
            break;
        }
        vst[now] = 1;
        r.pb(now);
    }
    int st_idx = -1;
    for(int i=0; i<sz(r);++i)
    {
        if (r[i] == st_val)
        {
            st_idx = i;
            break;
        }
    }
    //
    //debug(st_idx);
    int cyc_sum = 0;
    for(int i=st_idx; i<sz(r);++i)
        cyc_sum = (cyc_sum + r[i]);
    //debug(cyc_sum);
    int len = sz(r) - st_idx;
    //debug(len);
    if (n <= sz(r))
    {
        int ret = 0;
        for(int i=0; i < n; ++i)
            ret = (ret + r[i]);
        cout << ret << '\n';
        return;
    }
    int ans = 0;
    for (int i = 0; i < st_idx; ++i) ans = (ans + r[i]);
    n -= st_idx;
    int n_c =n/len;
    ans = (ans + n_c * cyc_sum);
    n -= n_c * len;
    for (int i = st_idx; i< st_idx + n; ++i)
        ans = (ans + r[i]);
    cout << ans << '\n';
    //
}

signed main()
{
    int T = 1;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(22);
    // cin >> T;
    for(int i=1;i<=T;++i)
    {
        //cout << "Case #" << i << '\n';
        solve();
    }
    return 0;
}
