#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <math.h>
#define pb push_back
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 100005;
const ll mod = 1e9+7;
const int lim = 1e5;

mt19937_64 mt_rnd_64(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) {
    return (mt_rnd_64() % (r-l+1)) + l;
}

ll n, a[N], l[N], mx;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        l[i] = INT_MAX;
    }
    for (int i=1; i<=n; i++)
    {
        int L = 1, R = mx + 1;
        while (R - L > 1)
        {
            int mid = (L+R)/2;
            if (a[i] <= l[mid]) L = mid;
            else R = mid;
        }
        if (a[i] <= l[L] && i != 1 && l[R] == INT_MAX) mx ++;
        if (a[i] <= l[L] && i != 1) l[R] = max((l[R]==INT_MAX?0:l[R]), a[i]);
        else l[L] = max(l[L], a[i]);
        if (i == 1) l[1] = a[i], mx ++;
    }
    for (int i=n; i>=1; i--)
    {
        if (l[i] != INT_MAX)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
