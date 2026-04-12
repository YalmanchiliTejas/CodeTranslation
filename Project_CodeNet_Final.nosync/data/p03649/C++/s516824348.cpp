#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);ios::sync_with_stdio(false);

signed main()
{
    ll n, ans = 0;
    cin >> n;
    priority_queue<ll> q;
    queue<ll> q2;
    rep(i, n)
    {
        ll x;
        cin >> x;
        q.push(x);
    }

    while (q.top() > n - 1)
    {
        ll now = q.top(), p;
        q.pop();

        if (now >= 2 * n - 1)
        {
            ans += (now - n + 1) / n;
            p = (now - n + 1) / n;
            while (!q.empty())
            {
                ll next = q.top() + p;
                q.pop();
                q2.push(next);
            }

            q.push(now- p*n);

            while (!q2.empty())
            {
                q.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            ans++;
            p = 1;

            while (!q.empty())
            {
                ll next = q.top() + p;
                q.pop();
                q2.push(next);
            }

            q.push(now - n);

            while (!q2.empty())
            {
                q.push(q2.front());
                q2.pop();
            }
        }
    }

    cout << ans << endl;
}