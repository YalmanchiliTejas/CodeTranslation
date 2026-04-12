#include<bits/stdc++.h>
using namespace std;

long long memo[200005][2], a[200005];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memo[2][0] = a[1], memo[2][1]= a[2];
    for (int i = 3; i <= n; i++) {
        if (i%2 == 0) {
            memo[i][0] = a[i - 1] + memo[i - 2][0];
            memo[i][1] = a[i] + max(memo[i - 1][0], max(memo[i - 2][0], memo[i - 2][1]));
        }
        else {
            memo[i][0] = max(memo[i - 1][1], memo[i - 1][0]);
            memo[i][1] = a[i] + max(max(memo[i - 2][0], memo[i - 2][1]), max(memo[i - 3][0], memo[i - 3][1]));
        }
    }
    cout << max(memo[n][0], memo[n][1]) << "\n";
}
