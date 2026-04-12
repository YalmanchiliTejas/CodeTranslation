#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

const int N = 1e6;

int ans[N];
int c[N];
vector<pair<int, int> > qs[N];
int lst[N];

int fenw[N];

void add(int pos, int x)
{
    while (pos < N)
    {
        fenw[pos] += x;
        pos = pos | (pos + 1);
    }
}

int get(int x)
{
    int res = 0;
    while (x >= 0)
    {
        res += fenw[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

int get(int l, int r)
{
    if (l == 0) return get(r);
    return get(r) - get(l - 1);
}

signed main()
{
    int x;
    cin >> x;
    if (x >= 30)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        qs[r].push_back({l, i});
    }
    for (int i = 0; i < N; i++) lst[i] = -1;
    for (int i = 0; i < n; i++)
    {
        if (lst[c[i]] != -1)
            add(lst[c[i]], -1);
        add(i, 1);
        lst[c[i]] = i;
        for (int j = 0; j < qs[i].size(); j++)
        {
            ans[qs[i][j].second] = get(qs[i][j].first, i);
        }
    }
    forn(i, q) cout << ans[i] << "\n";
}
