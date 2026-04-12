#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
int n;
vl pre;
vl ar;

ll recurse(int i, int j, bool player) {
    if (i == j)
        return ar[i];
    ll best = 0;
    if (player) {
        best = ar[i] + ((pre[j + 1] - pre[i + 1]) - recurse(i + 1, j, 0));
        best = max(best, ar[j] + ((pre[j] - pre[i]) - recurse(i, j - 1, 0)));
    } else {
        // Other player's turn so Player 1 does not get points for choosing
        // Also, player 2 will make move that gives least poitns to Player 1
        ll worst = ((pre[j + 1] - pre[i + 1]) - recurse(i + 1, j, 1));
        ll worst2 = max(worst, ((pre[j] - pre[i]) - recurse(i, j - 1, 1)));
        cout << " worst: " << worst << endl;
        cout << " worst2: " << worst << endl;
        best = worst2;
    }
    cout << "Player " << (player ? 1 : 2) << " | " << i << " " << j << "  == " << best << endl;
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ar.resize(n);
    pre.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pre[i + 1] = pre[i] + ar[i];
    }

    // ll ans = recurse(0, n - 1, 1);

    ll dp[n][n];
    for (int L = n - 1; L >= 0; --L) {
        for (int R = L; R < n; ++R) {
            if (L == R) {
                dp[L][R] = ar[L];
            } else {
                dp[L][R] = max(ar[L] - dp[L + 1][R], ar[R] - dp[L][R - 1]);
            }
        }
    }

    cout << dp[0][n - 1];
}