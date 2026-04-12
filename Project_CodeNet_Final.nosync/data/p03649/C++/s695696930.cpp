#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
ll arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    ll ans = 0;
    while (true)
    {
        bool found = false;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] >= N)
            {
                found = true;
                ll nv = arr[i] / N;
                arr[i] -= nv * N;
                for (int j = 0; j < N; j++)
                    if (j != i)
                        arr[j] += nv;
                ans += nv;
            }
        }
        if (!found) break;
    }
    cout << ans << "\n";
}