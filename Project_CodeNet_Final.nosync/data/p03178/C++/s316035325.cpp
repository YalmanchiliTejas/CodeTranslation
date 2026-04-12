#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const int INF = 1001001001;
const int mod = 1e+9 + 7;

#define chadd(x, y) x = (x + y) % mod

ll dp[10005][105][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int d;
    cin >> s >> d;
    int n = s.length();

    dp[0][0][1] = 1;
    for(int i = 0; i < n; ++i){
        int num = s[i] - '0';
        for(int m = 0; m < 10; ++m){
            for(int j = 0; j < d; ++j){
                int after = (m + j) % d;
                if(m > num){
                    chadd(dp[i+1][after][0], dp[i][j][0]);
                }
                else if(m == num){
                    chadd(dp[i+1][after][1], dp[i][j][1]);
                    chadd(dp[i+1][after][0], dp[i][j][0]);
                }
                else{   // m < num
                    chadd(dp[i+1][after][0], dp[i][j][1]);
                    chadd(dp[i+1][after][0], dp[i][j][0]);
                }
            }
        }
    }

    // for(int i = 0; i <= n; ++i){
    //     for(int j = 0; j < d; ++j){
    //         for(int k = 0; k < 2; ++k){
    //             cerr << dp[i][j][k] << " ";
    //         }
    //         cerr << "\n";
    //     }
    //     cerr << "\n";
    // }

    // -1 は 0 の分を取り除くための減算処理
    ll res = (dp[n][0][0] + dp[n][0][1] - 1) % mod;
    if(res < 0) res += mod;
    cout << res << endl;
}