#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int h = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int H;
        cin >> H;
        if (h <= H)
        {
            h = H;
            ++ans;
        }
    }
    cout << ans << endl;
}