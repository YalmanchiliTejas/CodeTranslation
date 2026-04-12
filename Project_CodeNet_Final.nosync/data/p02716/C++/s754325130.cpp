#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint dp[212345][2][3];

template<class T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
    lint n;
    cin >> n;

    vector<lint> a(n);
    for(auto& elem : a)  cin >> elem;

    fill(&dp[0][0][0], &dp[212345][0][0], -1e18);
    dp[0][0][0] = 0;
    for(lint i=0; i<n; i++)
    for(lint p=0; p<2; p++)
    for(lint m=0; m<3; m++) {
        if(p == 0) {
            chmax(dp[i+1][1][m], dp[i][p][m] + a[i]);
            if(m+1 < 3) chmax(dp[i+1][0][m+1], dp[i][p][m]);
        } else {
            chmax(dp[i+1][0][m], dp[i][p][m]);
        }
    }

    if(n%2) {
        cout << max(dp[n][0][1], dp[n][1][2]) << endl;
    } else {
        cout << max(dp[n][0][0], dp[n][1][1]) << endl;
    }
}