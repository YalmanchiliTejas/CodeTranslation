#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cmath>
#include <numeric>
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            ans -= 2 * a[i];
        }
        for (int i = n / 2; i < n; i++)
        {
            ans += 2 * a[i];
        }
        ans = ans - a[n / 2] + a[n / 2 - 1];
    }
    else if (n % 2 == 1)
    {
        //大きいのが多い方
        for (int i = 0; i < n / 2; i++)
        {
            ans -= 2 * a[i];
        }
        for (int i = n / 2; i < n; i++)
        {
            ans += 2 * a[i];
        }
        ans = ans - a[n / 2] - a[n / 2 + 1];
        //小さいのが多い方
        ll tmp_ans = 0;
        for (int i = 0; i < n / 2 + 1; i++)
        {
            tmp_ans -= 2 * a[i];
        }
        for (int i = n / 2 + 1; i < n; i++)
        {
            tmp_ans += 2 * a[i];
        }

        tmp_ans = tmp_ans + a[n / 2] + a[n / 2 - 1];

        ans = max(tmp_ans, ans);
    }
    cout << ans << endl;
    return 0;
}