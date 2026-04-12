#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define UM unordered_map
#define ALL(a) (a).begin(), (a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll, ll> pii;
const long long INF = 1LL << 58;
struct Edge
{
    ll s, t, d;
};
typedef vector<vector<Edge>> Graph;
typedef vector<pii> vpii;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

signed main()
{
    int N, X;
    cin >> N >> X;
    int bp[52][2];
    REP(i, 52)
    {
        bp[i][0] = 2;
        bp[i][1] = 1;
    }
    bp[0][0] = 0;
    bp[0][1] = 1;
    REP(i, 51)
    {
        bp[i + 1][0] += bp[i][0] * 2;
        bp[i + 1][1] += bp[i][1] * 2;
    }
    int ans = 0;
    for (int i = N; i >= 0; i--)
    {
        if (i == 0)
            ans++;
        else if (X == 1)
            break;
        else if (X < 1 + bp[i - 1][0] + bp[i - 1][1])
        {
            X -= 1;
        }
        else if (X == 1 + bp[i - 1][0] + bp[i - 1][1])
        {
            ans += bp[i - 1][1];
            break;
        }
        else if (X == 1 + bp[i - 1][0] + bp[i - 1][1] + 1)
        {
            ans += bp[i - 1][1] + 1;
            break;
        }
        else if (X < 1 + bp[i - 1][0] + bp[i - 1][1] + 1 + bp[i - 1][0] + bp[i - 1][1])
        {
            ans += bp[i - 1][1] + 1;
            X -= 1 + bp[i - 1][0] + bp[i - 1][1] + 1;
        }
        else
        {
            ans += bp[i][1];
            break;
        }
    }
    cout << ans << endl;
    //system("pause");
}
