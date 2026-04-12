#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x >= mx)
        {
            ans++;
            mx = max(x, mx);
        }
    }
    cout << ans << endl;
}