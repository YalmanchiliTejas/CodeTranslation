#include <bits/stdc++.h>

#define taskname ""
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 2e5 + 10;
const ll inf = 1e18L;

int n, m;
ll dp[maxN], add[maxN], res = 0;
vector <pair <int, ll>> rem[maxN];
struct node
{
    ll val, lazy;
} f[maxN * 4];
int L, R;
ll val;

void down(int x)
{
    ll t = f[x].lazy;
    f[x].lazy = 0;
    f[x * 2].lazy += t;
    f[x * 2].val += t;
    f[x * 2 + 1].lazy += t;
    f[x * 2 + 1].val += t;
}

void update(int x, int low, int high)
{
    if (high < L || low > R)
    {
        return;
    }
    if (high <= R && low >= L)
    {
        f[x].val += val;
        f[x].lazy += val;
        return;
    }
    int mid = (low + high) / 2;
    down(x);
    update(x * 2, low, mid);
    update(x * 2 + 1, mid + 1, high);
    f[x].val = max(f[x * 2].val, f[x * 2 + 1].val);
}

ll query(int x, int low, int high)
{
    if (high < L || low > R)
    {
        return -inf;
    }
    if (high <= R && low >= L)
    {
        return f[x].val;
    }
    int mid = (low + high) / 2;
    down(x);
    return max(query(x * 2, low, mid), query(x * 2 + 1, mid + 1, high));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(f, f + maxN * 4, node{-inf, 0});
    while (m--)
    {
        int l, r;
        ll c;
        cin >> l >> r >> c;
        add[l] += c;
        rem[r].eb(l, c);
    }
    L = 1, R = 1, val = inf;
    update(1, 1, n);
    for1(i, n)
    {
        //Put 1 at index i
        //Add the costs of all ranges start at index i into previous index
        L = 1, R = i, val = add[i];
        update(1, 1, n);
        //Get the answer
        L = 1, R = i;
        ll best = query(1, 1, n);
        //Update current answer to segment tree
        L = i + 1, R = i + 1, val = best + inf;
        update(1, 1, n);
        uax(res, best);
        //Remove the costs of all ranges end at index i which added before
        for (auto &rn: rem[i])
        {
            L = 1;
            R = rn.fi;
            val = -rn.se;
            update(1, 1, n);
        }
    }
    cout << res;
    return 0;
}
