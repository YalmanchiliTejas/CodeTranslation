#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n" 
#define p pair<int, int>
#define arrinp(i, a, start, end); for(ll i = start; i <= end; i++) cin >> a[i];
#define arrout(i, a, start, end); for(ll i = start; i <= end; i++) cout << a[i] << " ";
#define swap(a, b) {a = a + b; b = a - b; a = a - b;
#define forfront(i, start, end) for(ll i = start; i <= end; i++)
#define forback(i, start, end) for(ll i = start; i >= end; i--)
#define out(x) cout << x << " ";
#define outline(x) cout << x << endl;
#define sortvector(v) sort(v.begin(), v.end());
#define sortvectorrev(v) sort(v.rbegin(), v.rend());
#define inf INT64_MAX
int32_t main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    arrinp(i, a, 1, n);
    vector<int> suf(n + 2);
    suf[n] = a[n];
    suf[n + 1] = 0;
    for(int i = n - 1; i > 0; i--)
    {
        suf[i] = suf[i + 1] + a[i];
        suf[i] %= mod;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += (a[i]*suf[i + 1])%mod;
        ans %= mod;
    }
    outline(ans)
    return 0;
}