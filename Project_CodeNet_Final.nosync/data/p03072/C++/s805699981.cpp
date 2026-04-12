#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int H[200];
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
    }
    int ma = H[0];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ma = max(ma, H[i]);
        if (ma <= H[i])
            cnt++;
    }
    cout << cnt << endl;
}
