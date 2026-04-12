// #define _GLIBCXX_DEBUG // for STL debug (optional)
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
#include <unordered_map>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1LL << 60;
const ll MOD = 1000000007LL;

int N, S[100010];
unordered_map<int, int> dp[100010];

void solve(int k, int C) {
    if(dp[k].count(C) and dp[k][C] != -INF) return;
    if(k > 0) {
        solve(k-1, C);
        int A = N - 1 - k*C;
        dp[k][C] = dp[k-1][C] + S[A] + S[k*C]; 
    }
    else dp[k][C] = 0;
}

signed main() {
    cin >> N;
    for(int i=0; i<N; i++) cin >> S[i];

    // ありえる k, C の列挙
    for(int A=1; A<=N-2; A++) {
        int kC = N - 1 - A;

        // 約数列挙
        vector<int> ks;
        for(int k=1; k*k<=kC; k++) {
            if(kC % k == 0) {
                ks.push_back(k);
                if(k*k != kC) ks.push_back(kC/k);
            }
        }

        for(const auto &d : ks) {
            int k = d, C = kC / d;
            dp[k][C] = -INF;
        }
    }

    for(int k=N-1; k>=1; k--) {
        for(auto &e : dp[k]) {
            int C = e.first;
            solve(k, C);
        }
    }

    int ans = 0;
    for(int k=N-1; k>=0; k--) {
        for(auto &e : dp[k]) {
            int C = e.first, val = e.second;
            int A = N - 1 - k*C;

            if(A <= 0 or C <= 0 or A <= C) continue;
            if(A%C == 0 and 0 <= A/C and A/C <= k) continue;
            chmax(ans, val);
        }
    }
    cout << ans << endl;
    return 0;
}
