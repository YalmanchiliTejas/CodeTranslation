#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int main()
{
    ll n;
    cin >> n;
    vector<ll> std_cnt(26, 110);
    rep(i, n)
    {
        string s;
        cin >> s;
        int sn = s.length();
        vector<ll> cnt(26, 0);
        // count the number of alphabets in each s
        rep(j, sn)
        {
            cnt[s[j] - 'a']++;
        }
        // find the minimum number of alphabets in each s
        rep(j, 26)
        {
            std_cnt[j] = min(std_cnt[j], cnt[j]);
        }
    }

    string ans = "";
    // for each alphabets
    rep(i, 26)
    {
        // print as many times as std_cnt[i] has
        rep(j, std_cnt[i])
        {
            ans += (char)(i + 'a');
        }
    }
    cout << ans << endl;

    return 0;
}