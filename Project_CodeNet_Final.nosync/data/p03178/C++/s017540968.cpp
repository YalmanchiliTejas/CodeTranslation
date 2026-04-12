#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string k; cin>>k;
    int d; cin>>d;
    int n = k.size();

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(d, vector<ll>(2, 0)));
    dp[0][0][0] = 1;

    for(int i=0; i<n; i++){
        int cur = k[i] - '0';
        for(int pre=0; pre<d; pre++){
            for(int flg=0; flg<2; flg++){
                if(dp[i][pre][flg] == 0) continue;
                for(int j=0; j<=(flg?9:cur); j++){
                    dp[i+1][(pre+j)%d][flg||j<cur] += dp[i][pre][flg];
                    dp[i+1][(pre+j)%d][flg||j<cur] %= MOD;
                }
            }
        }
    }

    cout << (dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD << endl;

    return 0;
}