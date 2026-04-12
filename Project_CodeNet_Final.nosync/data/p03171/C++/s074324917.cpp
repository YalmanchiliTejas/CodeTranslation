#include <bits/stdc++.h>

using namespace std;

int n;
int arr[3000];
long long memo[2][3000][3000];
bool done[2][3000][3000];

long long dp(bool player, int a, int b)
{
    if (a > b)
        return 0;
    if (done[player][a][b])
        return memo[player][a][b];
    long long res;
    if (!player)
        res = max(arr[a] + dp(!player, a + 1, b), arr[b] + dp(!player, a, b - 1));
    else
        res =  min(dp(!player, a + 1, b) - arr[a], dp(!player, a, b - 1) - arr[b]);

    done[player][a][b] = true;
    memo[player][a][b] = res;
    return res;
}



int main(void)
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    long long result;
    result = dp(0, 0, n - 1);
    cout << result << endl;
    
}
