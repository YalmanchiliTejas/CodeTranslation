#include <iostream>
#include <climits>

using namespace std;

#define INF 2000000000
#define N 100000

int a, b, c, x, y, ans;

void solve()
{
    ans = INT_MAX;

    for (int i = 0; i <= N; i++) {
        int sum = 2*c*i;

        sum += a*max(0, x-i);
        sum += b*max(0, y-i);

        if (sum < ans) ans = sum;
    }
}

int main()
{
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

    solve();

    printf("%d\n", ans);

    return 0;
}