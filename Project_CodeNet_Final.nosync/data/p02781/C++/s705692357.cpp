#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a, ll b)
{
    ll r = 1;
    for (;b;b>>=1,a=a*a)
        if (b&1)
            r=r*a;
    return r;
}
ll c(ll n, ll k)
{
    if (k < 0 || k > n)
        return 0;
    ll ret = 1;
    for (int i = 0; i < k; ++i)
        ret = ret * (n - i) / (i + 1);
    return ret;
}
ll solve(string s, int k)
{
    int n = s.size();
    if (n == 0 || k == 0)
        return 0;
    long long ans = 0;
    ans += (s[0] - '1') * c(n - 1, k - 1) * qpow(9, k - 1);
    ans += c(n - 1, k) * qpow(9, k);
    int j;
    for (j = 1; j < n; ++j)
        if (s[j] != '0')
            break;
    return ans + solve(s.substr(j), k - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    int w = 0;
    for (char c : s)
        w += c != '0';
    cout << solve(s, k) + (w >= k) << endl;
}
