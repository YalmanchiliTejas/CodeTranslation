#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    // int d, t, s;

    // cin >> d >> t >> s;

    //it had better to use double or calculate as multiplier
    // if (d / s < t)
    // {
    //     cout << "Yes" << endl;
    // }
    // else if (d / s == t && d % s == 0)
    // {
    //     cout << "Yes" << endl;
    // }
    // else
    // {
    //     cout << "No" << endl;
    // }

    // string s, t;
    // cin >> s >> t;

    // int sum = 0, tmp;
    // for (int i = 0; i < s.length() - t.length() + 1; i++)
    // {
    //     tmp = 0;
    //     for (int j = 0; j < t.length(); j++)
    //     {

    //         if (s[i + j] == t[j])
    //         {
    //             tmp++;
    //         }
    //     }
    //     if (sum < tmp)
    //     {
    //         sum = tmp;
    //     }
    // }
    // cout << t.length() - sum << endl;
    int mod = 1000000007;
    int n;
    cin >> n;
    vector<int> v(n);
    vector<long long> sum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum[i + 1] = sum[i] + v[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long sum_n = (sum[n] - sum[i + 1]) % mod;
        ans += sum_n * v[i];
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}