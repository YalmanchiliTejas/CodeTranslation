#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int BestHeight = -1;

    for (int i = 0; i < n; i++)
    {
        BestHeight = max(BestHeight, h[i]);
        if(BestHeight <= h[i])
            ans++;
    }
    cout << ans << endl;
}