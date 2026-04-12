#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1) {
        int n; cin >> n;
        if (n==0) break;

        vector<int> vec(n);
        rep(i, n) cin >> vec[i];

        int ans = accumulate(all(vec), 0);
        sort(all(vec));
        ans -= vec.front();
        ans -= vec.back();

        ans /= n-2;
        cout << ans << endl;
    }
}
