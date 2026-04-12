#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, count = 1;
    cin >> n;
    vector<int> h(n);
    cin >> h[0];
    int tmp = h[0];
    for (int i = 1; i < n; i++)
    {
        cin >> h[i];
        tmp = max(tmp, h[i-1]);
        if (tmp <= h[i])
            count++;
    }
    cout << count << endl;
    return 0;
}
