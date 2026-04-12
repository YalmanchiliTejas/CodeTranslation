#include <bits/stdc++.h>

#define llint long long int

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[N - i - 1];
    }
    vector<int> dp(N, INT_MAX);

    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), A[i] + 1);

        dp[it - dp.begin()] = A[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (dp[i] == INT_MAX)
        {
            cout << i << endl;

            return 0;
        }
    }
    cout << N << endl;
}