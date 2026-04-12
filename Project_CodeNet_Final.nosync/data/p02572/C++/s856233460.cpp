#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define printclock cerr << "Time : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << "ms\n";
#define deb2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl
#define deb1(x) cout << #x << ": " << x << endl
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define prec(n) fixed << setprecision(n)
#define all(a) a.begin(), a.end()
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pii pair<int, int>
#define vii vector<int>
#define ld long double
#define int long long
#define mp make_pair
#define pb push_back
#define endl "\n";
#define mod 1000000007
inline void get(vector<int> &arr, int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
}
inline void print(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
/*----------------------------------TEMPLATE------------------------------------*/
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    fast;
    /*----------------------------PEEPEEPOOPOO-------------------------------------*/
    int t;
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vii v;
        get(v, n);
        vii suff(n);
        suff[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = v[i] + suff[i + 1];
        }
        int ans = 0;
        rep(i, 0, n - 1)
        {
            ans = ((ans % mod) + ((v[i] % mod) * (suff[i + 1] % mod)) % mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
/*--------------------------------PEEPEEPOOPOO-------------------------------------*/