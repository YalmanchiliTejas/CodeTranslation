
#include <iostream>
#include <iomanip> //! for setprecision(10)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MOD = 1000000007;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int H, W;
    cin >> H >> W;

    vector<string> A;
    rep(i, H) {
        string s;
        cin >> s;
        if (s.find('#') != string::npos) {
            A.push_back(s);
        }
    }

    vector<string> ans(A.size());
    rep(x, W) {
        bool allWhite = true;
        for (int y = 0; allWhite && y < A.size(); ++y) {
            if (A[y][x] == '#') {
                allWhite = false;
            }
        }
        if (!allWhite) {
            for (int y = 0; y < A.size(); ++y) {
                ans[y] += A[y][x];
            }
        }
    }

    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}
