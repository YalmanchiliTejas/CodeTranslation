#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    string s;
    int K;
    cin >> s;
    cin >> K;
    int N = s.size();
    vector<int> nums(N, 0);
    reverse(ALL(s));
    REP(i, N) {
        nums[i] = s[i] - '0';
    }
    vector<vector<LL>> dpLess(N, vector<LL>(K + 1, 0));
    vector<vector<LL>> dpEq(N, vector<LL>(K + 1, 0));
    auto f = [](auto x){return max(x, 0);};
    REP(i, N) {
        dpLess[i][0] = 1;
    }
    dpLess[N - 1][1] = nums[N - 1] - 1;
    dpEq[N - 1][1] = 1;
    for(int i = N - 2;0 <= i;i--) {
        for(int k = 1;k <= K;k++) {
            dpLess[i][k] = dpLess[i + 1][k] + dpLess[i + 1][k - 1]*9 + dpEq[i + 1][k - 1]*f(nums[i] - 1);
            if(0 < nums[i]) {
                dpLess[i][k] += dpEq[i + 1][k];
            }
            if(nums[i] == 0) {
                dpEq[i][k] = dpEq[i + 1][k];
            }
            if(nums[i] != 0) {
                dpEq[i][k] = dpEq[i + 1][k - 1];
            }
        }
    }
    cout << dpLess[0][K] + dpEq[0][K] << endl;
    return 0;
}

