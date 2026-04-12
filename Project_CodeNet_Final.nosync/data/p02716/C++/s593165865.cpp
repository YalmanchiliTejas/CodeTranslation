#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int>  pi;
typedef long long       ll;
const ll INF=1e18;
const int MAX=2e5+9;
int n, a[MAX];
map<pi, ll> memo;

ll dp(int i, int rest) {
    if (i>n) {
        if (rest) {
            return -INF;
        }

        return 0;
    }

    if (memo.find({i, rest})!=memo.end()) {
        return memo[{i, rest}];
    }

    if (rest>((n-i+1)+1)/2) {
        return memo[{i, rest}]=-INF;
    }

    memo[{i, rest}]=dp(i+1, rest);
    if (rest) {
        memo[{i, rest}]=max(memo[{i, rest}], a[i]+dp(i+2, rest-1));
    }

    return memo[{i, rest}];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }

    cout << dp(1, n/2);

    return 0;
}
