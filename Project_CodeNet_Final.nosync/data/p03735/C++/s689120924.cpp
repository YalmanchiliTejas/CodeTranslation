#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
pair <ll, ll> arr[MAXN];
ll hi, lo;

int main()
{
    ios_base::sync_with_stdio(0);
    
    hi = -1e12;
    lo = 1e12;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        if (arr[i].first > arr[i].second)
            swap (arr[i].first, arr[i].second);

        lo = min (lo, arr[i].first);
        hi = max (hi, arr[i].second);
    }
    sort (arr, arr + N);

    ll hmin = hi;
    for (int i = 0; i < N; i++)
        hmin = min (hmin, arr[i].second);
    ll ans = (hi - hmin) * (arr[N-1].first - lo);

    ll nhi = -1e9, nlo = 1e9;
    for (int i = 0; i < N - 1; i++)
    {
        nhi = max (nhi, arr[i].second);
        nlo = min (nlo, arr[i].second);
        ans = min (ans, (max (nhi, arr[N-1].first) - min (nlo, arr[i+1].first)) * (hi - lo));
    }
    cout << ans << "\n";
}