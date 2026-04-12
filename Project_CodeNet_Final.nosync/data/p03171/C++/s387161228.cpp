#include <iostream>
#include <fstream>
using namespace std;\
long long n, a[3005], F[3005][3005], S[3005];
int main()
{
    //freopen("DEQUE.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) S[i] = S[i - 1] + a[i];

    for (int cnt = 0; cnt <= n - 1; cnt++)
        for (int i = 1; i <= n - cnt; i++)
        {
            int j = i + cnt;
            F[i][j] = S[j] - S[i - 1] - min(F[i + 1][j], F[i][j - 1]);
        }
    cout << 2 * F[1][n] - S[n];
    return 0;
}
