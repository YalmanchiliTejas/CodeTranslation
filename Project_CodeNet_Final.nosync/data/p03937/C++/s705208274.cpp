#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define le length()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (__typeof(n) i = 0; i < n; i++)
#define repo(i, n) for (__typeof(n) i = 1; i <= n; i++)
#define eps 1e-6
#define pi 3.141592653589793
#define c(a) cout << a << "\n";
#define a(a)         \
    for (auto i : a) \
        cout << i << " ";
typedef vector<int> vii;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main()
{

    ll n, m, c = 0;
    cin >> n >> m;
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(i, s.le)
        {
            if (s[i] == '#')
                c++;
        }
    }
    if (c == n + m - 1)
        c("Possible") else c("Impossible")
}