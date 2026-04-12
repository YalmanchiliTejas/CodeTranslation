#include<bits/stdc++.h>
using namespace std;

//#pragma gcc optimize("O3,unroll-loop")
//#pragma gcc target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,abm,mmx,popcnt,tune=native")
#define int long long
//#define double long double
#define MOD 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = (pre[i - 1] + v[i]) % MOD;

    int ans = 0;
    for (int i = n; i > 1; i--)
        ans = (ans + v[i] * pre[i - 1]) % MOD;
    cout << ans << '\n';

    return 0;
}

//      *   *  *****  *   *  *   *   ****  ****    ****     **    **
//     *   *  *      **  *  *   *  *      *   *  *        * *   * *
//    *****  *****  * * *  *   *  *      ****   *       *  *     *
//   *   *      *  *  **  *   *  *      *  *   *       *****    *
//  *   *  *****  *   *   ***    ****  *   *    ****     *   *****

//      *****  *****  *   *  *      *****  *   *  *****  *****
//        *   *   *  *   *  *        *    **  *    *    *   *
//       *   *   *  *****  *        *    * * *    *    *****
//   *  *   *   *    *    *        *    *  **    *    *
//  ****   *****    *    *****  *****  *   *    *    *
