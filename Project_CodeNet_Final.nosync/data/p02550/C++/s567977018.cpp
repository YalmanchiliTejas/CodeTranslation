#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 1e9+7
#define INF 1 << 30
#define MAX (1 << 20)
#define NINF (-(1 << 30))
#define Point pair<int, int>
#define triplet pair<pair<int, int>, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, m;

    cin >> n >> x >> m;

    int arr[m];

    for (int i = 0; i < m; i++) arr[i] = -1;

    ll a0 = x, ans = 0;

    int i = 0;

    vector<ll> sum;

    for (i = 0; i < m; i++) {
        ans += a0;
        if(arr[a0] != -1)
            break;
        sum.push_back(ans);
        arr[a0] = i;
        a0 = (a0 * a0) % m;
    }

    //cout << "st: " << arr[a0] << ", et: " << i << endl;

    ans = (ans - sum[arr[a0]]);

    ans = ans * ((n - min(((ll)arr[a0] + 1), n)) / (i - arr[a0]));

    ans += sum[min((ll)arr[a0], n-1)];

    ans += (sum[arr[a0] + ((n - min(((ll)arr[a0] + 1), n)) % (i - arr[a0]))] - sum[arr[a0]]);

    cout << ans << endl;

    return 0;
}