#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int R[8][8] = {};
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        R[a - 1][b - 1] = 1;
        R[b - 1][a - 1] = 1;
    }
    int array[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int ans = 0;
    do
    {
        if (array[0])
        {
            break;
        }
        bool can = true;
        for (int i = 1; i < N; ++i)
        {
            if (!R[array[i - 1]][array[i]])
            {
                can = false;
                break;
            }
        }
        if (can)
        {
            ++ans;
        }
    } while (next_permutation(array, array + N));
    cout << ans << endl;

    return 0;
}