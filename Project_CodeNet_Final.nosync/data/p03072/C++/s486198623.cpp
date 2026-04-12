#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n;
int h[500];
int ans;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++)
    {
        int t = 1;
        for (int j = 0; j < i; j++)
        {
            if (h[j] > h[i])
                t = 0;
        }
        ans += t;
    }
    cout << ans;
}
