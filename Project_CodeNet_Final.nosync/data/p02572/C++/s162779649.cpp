// *********************************************************************************
// *                        MURTAZA MUSTAFA KHUMUSI                                *
// *                        NIT-DGP,CSE - 2019-2023                                *
// *********************************************************************************

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1000000007;
#define loop(i, a, n) for (int i = a; i < n; i++)
#define loop1(i, b, n) for (int i = b; i <= n; i++)
#define loopit(a) for (auto it = a.begin(); it != a.end(); it++)
#define ms(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define pi pair<int, int>
#define ff first
#define ss second
#define bloop(i, a, b) for (int i = a; i > b; i--)
#define bloop1(i, a, b) for (int i = a; i >= b; i--)
#define PQ priority_queue<int> pq;
#define MPQ priority_queue<pi, vector<int>, greater<pi>> mpq;
#define io                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);
const int maxm = 100001;

void solve()
{

    ll n;
    cin >> n;
    ll ar[n];
    ll suf[n];
    ms(suf,0);

    loop(i, 0, n)
    {
        cin >> ar[i];
    }

    bloop1(i, n - 2, 0)
    {
        suf[i] = ((suf[i + 1]) % m + (ar[i + 1]) % m) % m;
    }

    ll ans = 0;
    loop(i, 0, n)
    {
        ans = (ans % m + (suf[i] * ar[i]) % m) % m;
    }
    cout << ans << "\n";
}

int main()
{
    io;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();

    return 0;
}
