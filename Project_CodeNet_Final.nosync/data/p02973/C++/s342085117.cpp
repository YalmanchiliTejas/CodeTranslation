#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
using ll = long long;

int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[N-1-i];
    }

    int ans = 0;
    vector<int> dp(N, INF);

    for (int i = 0; i < N; i++)
    {
        int pos = upper_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[pos] = A[i];
        ans = max(ans, pos+1);
    }

    cout << ans << endl;
    
    return 0;
}
