#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;
int h[MAXN];

int main()
{
    int n;
    cin >> n;
    int maxx = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x >= maxx)
        {
            ans++;
        }
        maxx = max(maxx, x);
    }
    cout << ans << endl;
    return 0;
}
