#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

const int MOD = 1000000007;

int main()
{
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();

    vector<vector<int> > dp(2, vector<int>(d, 0));
    dp[0][0] = 1;
    for(int i=0; i<n; ++i){
        vector<vector<int> > nextDp(2, vector<int>(d, 0));
        for(int x=0; x<2; ++x){
            for(int y=0; y<d; ++y){
                for(int a=0; a<=9; ++a){
                    if(x == 0 && s[i] - '0' < a)
                        continue;

                    int x2 = x;
                    if(a < s[i] - '0')
                        x2 = 1;
                    int y2 = (y + a) % d;
                    nextDp[x2][y2] += dp[x][y];
                    nextDp[x2][y2] %= MOD;
                }
            }
        }
        dp = move(nextDp);
    }

    int ans = (dp[0][0] + dp[1][0] - 1LL + MOD) % MOD;
    cout << ans << endl;

    return 0;
}
