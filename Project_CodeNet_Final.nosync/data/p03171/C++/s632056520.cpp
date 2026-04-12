#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 3002;
int N, q[MAX_N];
ll dp[MAX_N][MAX_N][2];
bool solved[MAX_N][MAX_N][2];

ll calc(int start, int end, bool turn) {
    if(start > end) return 0;
    if(solved[start][end][turn]) return dp[start][end][turn];

    if(turn)
        dp[start][end][turn] = max(q[start] + calc(start + 1, end, 0), q[end] + calc(start, end - 1, 0));
    else
        dp[start][end][turn] = min(-q[start] + calc(start + 1, end, 1), -q[end] + calc(start, end - 1, 1));

    solved[start][end][turn] = true;
    //cout << dp[start][end][turn] << endl;
    return dp[start][end][turn];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ll sum = 0;

    for(int i = 0; i < N; i++) {
        cin >> q[i];
        sum += q[i];
    }
        
    cout << calc(0, N - 1, 1) << "\n";

    return 0;
}
