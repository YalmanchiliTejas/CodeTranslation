#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {

    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string k;
    int d;
    cin >> k >> d;
    int n = k.size();

    vector< vector<int> > dp(d, vector<int>(2));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        vector< vector<int> > new_dp(d, vector<int>(2));
        for(int sum = 0; sum < d; sum++) {
            for(int already_smaller = 0; already_smaller < 2; already_smaller++) {
                for(int digit = 0; digit < 10; digit++) {
                    if(digit > k[i] - '0' && !already_smaller)
                        break;
                    int sum2 = (sum + digit) % d, as = already_smaller;
                    if(digit < k[i] - '0')
                        as = 1;
                    new_dp[sum2][as] = add(new_dp[sum2][as], dp[sum][already_smaller]);
                }
            }
        }
        dp = new_dp;
    }

    cout << add(add(dp[0][0], dp[0][1]), mod - 1) << endl;
    return 0;
}
