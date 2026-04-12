#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
constexpr ll mod = 1000000007;
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, m;
    cin >> n >> x >> m;
    VL dp(min(n, m) + 10, 0LL);
    set<ll> st;
    map<ll,ll> mp;
    ll next = x;
    ll unit = -1, srt, end;
    dp[1] = x;
    st.insert(x);
    mp[x] = 1;
    rep(i, 2, n+1) {
        ll cur = next;
        next = (cur * cur) % m;
        dp[i] = (dp[i-1] + next);
        if(st.count(next)) {
            srt = mp[next];
            end = i;
            unit = end - srt;
            break;
        } 
        st.insert(next);
        mp[next] = i;
    }
    if(unit == -1) {
        cout << dp[n] << endl;
        return 0;
    }
    ll ans = 0;
    ans += dp[srt-1];
    ll rem = n - srt + 1;
    ll mat = rem / unit;
    ans += (dp[end-1] - dp[srt-1]) * mat;
    ll nokori = rem - mat * unit;
    ans += dp[srt + nokori - 1] - dp[srt - 1];
    cout << ans << endl;
    return 0;
}