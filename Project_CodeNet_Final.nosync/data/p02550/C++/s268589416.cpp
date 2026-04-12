//
#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define f first
#define s second
#define what_is(x) cerr << #x << " is " << x << endl;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int INF = 1000000007;
const ll MOD = 1000000007;


void solve_test()
{
    ll n, x, m;
    cin >> n >> x >> m;
    if(m == 1)
    {
        cout << 0;
        return;
    }
    ll pos[m+1];
    for(int i=0; i<=m; i++)
    {
        pos[i] = -1;
    }
    ll val = x;
    ll ans = 0;
    ll period = 1;
    ll sum[m+1];
    ll st = n;
    memset(sum, 0, sizeof(sum));
    ll diff = 0;
    for(ll i=0; i<min(n, m); i++)
    {
        if(pos[val] != -1)
        {
            period = i - pos[val];
            st = pos[val];
            diff = sum[i-1];
            if(st > 0)
            {
                diff -= sum[st-1];
            }
            break;
        }
        sum[i] += val;
        pos[val] = i;
        val = (val*val) % m;
        if(i)
        {
            sum[i] += sum[i-1];
        }
    }

//    for(ll i=0; i<min(n, m); i++)
//    {
//        cout << sum[i] << " ";
//    }
//    cout << "\n";
//    what_is(st);
    if(st > 0)
        ans += sum[st-1];
    if (st != n)
    {
        ll q = (n - st) / period;
        ll r = (n - st) % period;
        what_is(ans);

        ans += q * diff;
//        what_is(st);
//        what_is(val);
//        what_is(period);
//        what_is(diff);
//        what_is(q);
//        what_is(r);
        for(ll i=0; i<r; i++)
        {
            ans += val;
            val = (val * val) % m;
        }
    }

    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    tests = 1;
    //cin >> tests;
    while(tests--)
    {
        solve_test();
    }
    return 0;
}
