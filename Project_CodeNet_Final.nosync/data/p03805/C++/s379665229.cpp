#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

#define FOR(i, start, end) for(ll i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> next(N+1);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        next[a].push_back(b);
        next[b].push_back(a);
    }

    vector<int> prm(N);
    REP (i, N) {
        prm[i] = i + 1;
    }

    int ans = 0;
    do {
        if (*prm.begin() != 1) {
            break;
        }
        for (vector<int>::iterator p = prm.begin(); p != prm.end(); p++) {
            if (p + 1 == prm.end()) {
                ans++;
                break;
            }
            vector<int> n = next.at(*p);
            if (find(n.begin(), n.end(), *(p + 1)) == n.end()) {
                break;
            }
        }
    } while (next_permutation(prm.begin(), prm.end()));

    cout << ans << endl;

    return 0;
}