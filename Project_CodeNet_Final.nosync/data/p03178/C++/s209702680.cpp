#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    string s;
    int d;
    cin>>s>>d;
    // dp[i][0] - #integers with sum_digits p*d + i using curr digit m as [0..9]
    // dp[i][1] - #integers with sum_digits p*d + i using curr digit m as [0..m]
    vector<vector<int>> prev(d, vector<int> (2, 0));
    prev[0][0] = prev[0][1] = 1;
    for(int i = s.size()-1; i>=0; i--) {
        vector<vector<int>> curr(d, vector<int> (2, 0));
        int m = (int) (s[i] - '0');
        for(int j=0; j<d; j++) {
            for(int k=0; k<10; k++) {
                curr[(j+k)%d][0] = (curr[(j+k)%d][0] + prev[j][0]) % mod;
                if(k < m) curr[(j+k)%d][1] = (curr[(j+k)%d][1] + prev[j][0]) % mod;
            }
            curr[(j+m)%d][1] = (curr[(j+m)%d][1] + prev[j][1]) % mod;
        }
        prev = curr;
    }
    cout<<(prev[0][1] - 1 + mod) % mod<<endl;
    return 0;
}
