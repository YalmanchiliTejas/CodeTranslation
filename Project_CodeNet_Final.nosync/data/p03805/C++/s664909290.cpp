
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N, 0));
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    int ans = 0;
    vector<int> v;
    REP(i, N-1) {
        v.push_back(i+1);
    }
    do {
        if (G[0][v[0]] == 0) continue;

        bool ok = true;
        REP(i, v.size() - 1) {
            if (G[v[i]][v[i+1]] != 1) {
                ok = false;
                break;
            }

        }
        if (!ok) continue;
        ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}
