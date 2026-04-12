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

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const ll mod = 1e+9 + 7;
const int INF = 1001001001;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

ll dp[105][2][105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    dp[0][1][0] = 1;
    for(int i = 0; i < n; ++i){
        int hoge = s[i] - '0';
        for(int x = 0; x < 10; ++x){
            if(x == 0){
                if(x < hoge){
                    for(int j = 0; j <= 100; ++j){
                        dp[i+1][0][j] += dp[i][0][j];
                        dp[i+1][0][j] += dp[i][1][j];
                    }
                }
                else if(x == hoge){
                    for(int j = 0; j <= 100; ++j){
                        dp[i+1][0][j] += dp[i][0][j];
                        dp[i+1][1][j] += dp[i][1][j];
                    }
                }
                else{
                    for(int j = 0; j <= 100; ++j){
                        dp[i+1][0][j] += dp[i][0][j];
                    }
                }
            }
            else{
                if(x < hoge){
                    for(int j = 0; j < 100; ++j){
                        dp[i+1][0][j+1] += dp[i][0][j];
                        dp[i+1][0][j+1] += dp[i][1][j];
                    }
                }
                else if(x == hoge){
                    for(int j = 0; j < 100; ++j){
                        dp[i+1][0][j+1] += dp[i][0][j];
                        dp[i+1][1][j+1] += dp[i][1][j];
                    }
                }
                else{
                    for(int j = 0; j < 100; ++j){
                        dp[i+1][0][j+1] += dp[i][0][j];
                    }
                }
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k] << endl;
}