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
    for (int i = 0; i < N; i++)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (H[i] < H[j])
            {
                flag = false;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
