#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cctype>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) cin >> S[i];
    
    vector<vector<int>> cnt(N, vector<int>(26, 0));
    REP(i, N) {
        for (char c : S[i]) ++cnt[i][c - 'a'];
    }
    string ans;
    REP(i, 26) {
        int k = 100;
        REP(j, N) k = min(k, cnt[j][i]);
        REP(j, k) ans.push_back('a' + i);
    }
    cout << ans << "\n";
    return 0;
}
