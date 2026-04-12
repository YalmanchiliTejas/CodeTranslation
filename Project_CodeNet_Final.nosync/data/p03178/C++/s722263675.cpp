#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll m(ll a) {
    return ((a%MOD)+MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string number;
    cin>>number;
    int n = (int)number.length();
    int d;
    cin>>d;
    vector<ll> dp(d, 0);
    int digit;
    digit = number[0]-'0';
    for (int i=0; i<digit; i++) {
        dp[i%d]++;
    }

    ll rem_for_max = digit%d;

    for (int i=1; i<n; i++) {
        vector<ll> new_dp(d, 0);
        for (int j=0; j<d; j++) {
            for (int k=0; k<=9; k++) {
                int value_to_be_added = (((j-k)%d)+d)%d;
                new_dp[j] = m(new_dp[j]+dp[value_to_be_added]);
            }
        }

        digit = number[i] - '0';

        for (int j=0; j<digit; j++) {
            new_dp[(j+rem_for_max)%d]++;
        }

        rem_for_max = (rem_for_max+digit)%d;

        new_dp.swap(dp);
    }

    if (rem_for_max==0) {
        dp[0]++;
    }

    cout << m(dp[0]-1) << endl;
    
}