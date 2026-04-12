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
    int ans = 1;
    for (int i = 1; i < N; i++)
    {
        int judge = 1;
        for (int j = 0; j < i; j++)
        {
            if (H[j] > H[i])
            {
                judge = 0;
            }
        }
        if (judge == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}