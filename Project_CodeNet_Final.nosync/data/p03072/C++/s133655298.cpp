#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int hi;
    int ans = 0;
    int h = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> hi;
        if (h <= hi)
            ans++;
        else
            continue;

        h = max(h, hi);
    }

    cout << ans << endl;
}