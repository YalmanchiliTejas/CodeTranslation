//
// Created on 2020/02/09.
//

//#include <bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>
#include <functional>

#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;


int main() {

    string s;
    int k;
    cin>>s;
    cin>>k;

     vector<vector<vector<int >>>dp(105,vector<vector<int >>(4,vector<int >(2,0)));

    dp[0][0][0] = 1;

    for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= 1; ++l) {
                for (int m = 0; m < 10; ++m) {
                    int ns = s[i] - '0';
                    int nl = l;
                    int nj = j;
                    if (m!=0) nj ++;
                    if (nj > k) continue;
                    if (m > ns && nl == 0) continue;
                    if (m < ns) nl = 1;
                    dp[i+1][nj][nl] += dp[i][j][l];
                }

            }
        }
    }
    int ans = 0;
    ans = dp[s.size()][k][0]+dp[s.size()][k][1];
    cout<<ans<<endl;


}
