#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector dp(N + 4, vector(3, 0L));
    vector<long> a(4);
    copy_n(istream_iterator<long>(cin), N, back_inserter(a));
    for(unsigned long i{4}; i < N + 4; ++i)if(i & 1)dp[i][1] = max({dp[i - 2][1] + a[i], dp[i - 3][0] + a[i], dp[i - 1][0]});
        else{
            dp[i][0] = dp[i - 2][0] + a[i];
            if(i > 4)dp[i][2] = max({dp[i - 2][2] + a[i], dp[i - 3][1] + a[i], dp[i - 4][0] + a[i], dp[i - 1][1], dp[i - 2][0]});
        }
    cout << dp.back()[1 + (N & 1)] << endl;
    return 0;
}