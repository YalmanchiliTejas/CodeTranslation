#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    int maxu = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (x >= maxu)
        {
            ++ans;
            maxu = x;
        }
    }
    cout << ans << endl;
    return 0;
}
