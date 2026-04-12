#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    int N, M;
    int a, b;
    int i;
    cin >> N >> M;
    vector<vector<bool>> E(N, vector<bool>(N, false));
    for (i = 0; i < M; ++i)
    {
        cin >> a >> b;
        E[a - 1][b - 1] = E[b - 1][a - 1] = true;
    }
    vector<int> p(N);
    for (int i = 0; i < N; i++) p[i] = i;
    int ans = 0;
    do
    {
        for (i = 1; i < N; i++)
        {
            if (!E[p[i - 1]][p[i]]) break;
        }
        if (i == N) ans++;
    }
    while (next_permutation(p.begin() + 1, p.end()));    
    cout << ans << endl;
    return 0;
}