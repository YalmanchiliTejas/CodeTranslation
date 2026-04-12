#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
using ll = long long;

const int maxN = 10123;
char k[maxN];
const int MOD = 1e9 + 7;

void add_self(int & a, int b) {
    a += b;
    if (a > MOD) {
        a -= MOD;
    }
}

int main(int argc, char *argv[]) {
    cin >> k;
    int D;
    cin >> D;
    int n = strlen(k);
    vector<vector<int> > dp(D, vector<int>(2));
    dp[0][0] = 1;
    for (int where = 0; where < n; ++where) {
        vector<vector<int> > new_dp(D, vector<int>(2));
        for (int sum = 0; sum < D; ++sum) {
            for (bool sm_already: {false, true} ) {
                for (int digit = 0; digit < 10; ++digit) {
                    if (digit > k[where] - '0' && !sm_already)
                        break;
                    add_self(new_dp[(sum + digit)%D][sm_already || digit < k[where] - '0'],
                             dp[sum][sm_already]);
                }
            }
        }
        dp = new_dp;
    }
    int ans = dp[0][true] + dp[0][false];
    ans--;
    if (ans < 0) {
        ans += MOD;
    }
    printf("%d\n", ans);
    return 0;
}