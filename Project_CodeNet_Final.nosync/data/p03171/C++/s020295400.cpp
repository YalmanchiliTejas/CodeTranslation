
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

int N;
vector<int> a;

LL dp[3001][3001];  //! [l][r] => answer when the deque is in [l..r] range, of course l <= r
bool done[3001][3001];

LL solve(int l, int r) {
    if (!done[l][r]) {
        if (N%2 == (r-l+1)%2) {
            //! taro's turn
            if (l == r) {
                dp[l][r] = a[l];
            } else {
                dp[l][r] = max(a[l] + solve(l+1,r), a[r] + solve(l,r-1));
            }
        } else {
            //! jiro's turn
            if (l == r) {
                dp[l][r] = -a[l];
            } else {
                dp[l][r] = min(-a[l] + solve(l+1,r), -a[r] + solve(l,r-1));
            }
        }
        done[l][r] = true;
    }

    return dp[l][r];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    cin >> N;
    a.resize(N);
    rep(i, N) cin >> a[i];

    cout << solve(0, N-1) << endl;

    return 0;
}
