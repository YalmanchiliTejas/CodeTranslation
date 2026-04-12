#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int H[N];
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    int ans = 0;
    int MaxHeight = -1;
    for (int i = 0; i < N; i++)
    {
        if (MaxHeight <= H[i])
        {
            ans++;
            MaxHeight = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}