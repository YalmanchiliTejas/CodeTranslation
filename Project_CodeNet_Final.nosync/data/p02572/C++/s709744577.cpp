#include <iostream>
#include <vector>

#define int __int128_t
#define MOD (int)1000000007

using namespace std;

signed main()
{
    signed n;
    cin >> n;

    int sum = 0;
    int msum = 0;
    int ssum = 0;
    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        sum += t;
        //sum %= MOD;
        ssum += t * t;
        //ssum %= MOD;
    }

    //sum %= MOD;
    msum = sum * sum;
    //msum %= MOD;

    signed ans = ((msum - ssum) / 2 + MOD) % MOD;
    cout << ans << endl;
}