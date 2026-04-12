#include <bits/stdc++.h>
using namespace std;

int n,x;
vector <int> V;
long long dp[3010][3010];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        V.push_back(x);
    }

    for (int L = n-1; L >= 0; L--) {
        for (int R = L; R < n; R++) {
            if (L == R) dp[L][R] = V[L];
            else{
                dp[L][R]=max(V[R] - dp[L][R - 1], V[L] - dp[L + 1][R]);
            }
        }
    }
    cout << dp[0][n-1];
}
