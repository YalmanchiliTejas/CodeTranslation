#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    string k;
    int d;
    cin>>k>>d;
    // dp[i][0] - #integers with sum_digits p*d + i using curr digit m as [0..9]
    // dp[i][1] - #integers with sum_digits p*d + i using curr digit m as [0..m]
    vector<vector<int>> prev(d, vector<int> (2, 0));
    prev[0][0] = prev[0][1] = 1;
    for(int i = k.size()-1; i>=0; i--) {
        vector<vector<int>> curr(d, vector<int> (2, 0));
        int m = (int) (k[i] - '0');
        for(int j=0; j<d; j++) {
            for(int k=0; k<10; k++) {
                curr[j][0] = (curr[j][0] + prev[(j - k + 9*d) % d][0]) % mod;
                if(k < m) curr[j][1] = (curr[j][1] + prev[(j - k + 9*d) % d][0]) % mod;
            }
            curr[j][1] = (curr[j][1] + prev[(j - m + 9*d) % d][1]) % mod;
        }
        prev = curr;
    }
    cout<<(prev[0][1] - 1 + mod) % mod<<endl;
    return 0;
}
