#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (i % 15 == 0 && i > 0)
            ans += 600;
        else
            ans += 800;
    cout << ans << '\n';
    return 0;
}
