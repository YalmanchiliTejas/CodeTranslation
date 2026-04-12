#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    int mod = 1000000007;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }

    long ans = 0;
    rep(i, n)
    {
        sum -= A[i];
        if (sum < 0)
            sum += mod;

        ans += A[i] * sum;
        ans %= mod;
    }

    cout << ans << endl;
}