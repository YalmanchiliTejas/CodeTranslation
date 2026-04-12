#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> b(a);
    sort(a.begin(), a.end());

    int ind = n / 2;
    map <int, int> ans;
    for (int i = 0; i < n; i++)
    {
        if (i < ind)
        {
            ans[a[i]] = a[ind];
        }
        else
        {
            ans[a[i]] = a[ind - 1];
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[b[i]] << ' ';
    return 0;
}
