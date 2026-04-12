#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1000000007
#define PI M_PI
#define ll long long
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define REPD(i, n) for (int i=n-1; i>=0; i--)
#define print(x) cout << x << endl;
#define debug(x) cout << #x << " = " << endl;

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> H(N);
    REP(i, N) cin >> H[i];

    int ans = 1;
    if (H[0] <= H[1]) {
        ++ans;
    }
    for (int i=2; i<N; ++i) {
        //if ((H[0] <= H[i]) && (H[1] <= H[i]) && (H[i-1] <= H[i])) {
        bool ok = true;
        for (int j=0; j<i; ++j) {
            if (H[j] <= H[i]) {
                continue;
            } else {
                ok = false;
            }
        }
        if (ok) {
            ++ans;
        }
    }
    print(ans);
}

int main()
{
    solve();

    return 0;
}
