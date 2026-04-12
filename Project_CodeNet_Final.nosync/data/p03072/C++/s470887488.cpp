#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ans = 0;
    int m = 0;
    int h[20] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        if (h[i] >= h[0] && h[i] >= m)
        {
            if (h[i] > m)
            {
                swap(m, h[i]);
            }

            ans++;
        }
    }
    cout << ans << endl;
}
