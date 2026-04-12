#include <bits/stdc++.h>
using namespace std;

#define N 20

int main(int argc, char const *argv[])
{
    int n;
    int h[N];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int top = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (top <= h[i])
        {
            top = h[i];
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
