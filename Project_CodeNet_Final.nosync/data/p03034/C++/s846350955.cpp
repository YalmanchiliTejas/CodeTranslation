#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;

    long long ans = 0;
    for(int d = 1; d < n / 2; ++d)
    {
        int t = 0; long long ps = 0;
        while(1)
        {
            ps += arr[t] + arr[n - t - 1];
            ans = max(ps, ans);
            t += d;
            if(n - t - 1 <= d || (n - 1) % d == 0 && (n - 1) <= 2 * t) break;
        }
    }

    cout << ans;
}
