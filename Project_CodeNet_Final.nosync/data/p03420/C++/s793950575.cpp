#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <fstream>
#define ni(n) scanf("%d", &n)
#define nl(n) scanf("%lld", &n)
#define nai(a,n) for (int i = 0; i < (n); i++) ni((a)[i])
#define nal(a,n) for (int i = 0; i < (n); i++) nl((a)[i])
#define case(t) printf("Case #%d: ", (t))
#define pii pair<int, int>
#define vii vector<pii>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double eps = 1e-9;
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << n * n << endl;
        return 0;
    }
    ll ans = k * k - k * (2 * n + 1) + n * (n + 1);
    ans /= 2;
    for (ll b = k + 1; b <= n; b++)
    {
        ll st = ((n - b + 1) / b + 1) * b;
        if ((n - b + 1) % b == 0) st = n - b + 1;
        if (st > n - k)
        {
            ans += (b - k) * ((n - k) / b);
            continue;
        }
        ans += (st - n + b - 1) * ((n - b + 1) / b);
        for (; st + b <= n - k; st += b)
        {
            ans += (b - 1) * st / b;
        }
        if (st + b > n - k)
        {
            ans += (n - k - st + 1) * (st / b);
        }
    }
    cout << ans << endl;
    return 0;
}
