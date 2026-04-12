#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

bool isMaximize(int i, int j, int n){
    int cnt = j-i+1;
    return (n - cnt) % 2 == 0;
}

ll _deque(vector<int>& s) {
    int n = s.size();
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int i = 0; i < n; ++ i) {
        dp[i][i] = isMaximize(i,i,n) ? s[i] : -s[i]; 
    }
    for (int k = 2; k <= n; ++ k) {
        for (int j = 0; j + k - 1 < n; ++ j) {
            if (isMaximize(j, j+k-1, n)) {
                dp[j][j+k-1] = max(dp[j][j+k-2]+s[j+k-1], dp[j+1][j+k-1]+s[j] );
            }
            else {
                dp[j][j+k-1] = min(dp[j][j+k-2]-s[j+k-1], dp[j+1][j+k-1]-s[j]);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int N; 
    cin>>N;
    vector<int> s(N);
    for (auto& e : s) { cin>>e; }
    cout<< _deque(s) <<endl;
    return 0;
}