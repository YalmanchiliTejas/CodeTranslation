#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1000000000 + 7;

void add(int& a, int b) {
    a += b;
    if(a >= M) a -= M;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    int d;
    cin >> s >> d;
    int n = (int) s.size();
    
    vector<int> dp[2] {vector<int>(d, 0), vector<int>(d, 0)};
    dp[1][0] = 1;
    for(int i = 0; i < n; ++i) {
        int digit = s[i] - '0';
        vector<int> new_dp[2] {vector<int>(d, 0), vector<int>(d, 0)};
        for(int j = 0; j < d; ++j) {
            add(new_dp[1][(j + digit % d) % d], dp[1][j]);
        }
        for(int x = digit - 1; x >= 0; --x) {
            for(int j = 0; j < d; ++j) {
                add(new_dp[0][(j + x % d) % d], dp[1][j]);
            }
        }
        for(int x = 0; x < 10; ++x) {
            for(int j = 0; j < d; ++j) {
                add(new_dp[0][(j + x % d) % d], dp[0][j]);
            }
        }
        swap(dp, new_dp);
    }

    cout << (-1LL + dp[1][0] + dp[0][0] + M) % M << '\n';
}
