#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);


int main() {
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    const ll min_val = ll(INT_MIN) * ll(10000);
    vector<vector<ll>> dp(n, vector<ll>(n, min_val));
    for(auto& val: arr)
        cin >> val;
    auto dfs = [&] (auto& self, int head, int tail) -> ll {
        if (dp[head][tail] != min_val) {
            return dp[head][tail];
        }
        if (head == tail) {
            return arr[head];
        }
        dp[head][tail] = max(arr[head] - self(self, head+1, tail),
                              arr[tail] - self(self, head, tail-1));
        return dp[head][tail];
    };
    cout << dfs(dfs, 0, n-1) << endl;
    return 0;
}


