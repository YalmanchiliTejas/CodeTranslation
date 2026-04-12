#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e15;
const int MAXN = 200*1000+5;
int a[MAXN];

map<pair<int, int>, ll> memo;

ll dp(int idx, int need) {
    if(idx < 0) {
        return need == 0 ? 0 : -inf;
    }
    if(need == 0) return 0;
    if(need > (idx+1)/2+1) return -inf;
    pair<int, int> state{idx, need};
    
    if(memo.count(state)) return memo[state];
    return memo[state] = max(dp(idx-1, need), dp(idx-2, need-1) + a[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << dp(n-1, n/2) << endl;
}
