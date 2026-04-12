/**
        ______________________
      AnTi-MiRaGe on Anti-Mage xD
      --------------------------
**/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <set>
#include <map>

#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()
#define show puts("Debug")
#define int long long

using namespace std;

int n, k, ans;

main()
{
    cin >> n >> k;
    if (k == 0)
    {
        cout << n * n << endl;
        return 0;
    }
    for (int i = k; i <= n; i++)
        ans += n - i;

    for (int i = k + 1; i <= n - k; i++)
    {
        for (int j = min(n, i + i); ;)
        {
            ans += max(0ll, j - ( (j % i == 0 ? j / i - 1 : j / i) * i + k) );

            if (j == n && j % i != 0 && j >= (j / i) * i + k )
                ans++;

            if (j >= n) break;

            j += i;

            if (j > n) j = n;
        }
    }
    cout << ans << endl;
}
/**
287927211
287933049
**/
