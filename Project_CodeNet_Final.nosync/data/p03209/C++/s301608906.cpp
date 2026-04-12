#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

ll dfs(ll n, ll X, vector<ll>& patty, vector<ll>& burger) {
    if (n == 0) return (X==1) ? 1 : 0;
    if (n == 1) return max(min(X-1, 3LL), 0LL);
    if (X <= burger[n-1] + 1)
        return dfs(n-1, X-1, patty, burger);
    else if (X == burger[n-1] + 2)
        return patty[n-1] + 1;
    else if (X > burger[n-1] + 2)
        return patty[n-1] + 1 + dfs(n-1, X-(burger[n-1]+2), patty, burger);
}
int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> patty(n+1, 0);
    vector<ll> burger(n+1, 0);

    patty[0] = burger[0] = 1;
    for(int i = 1; i <= n; i++) {
        patty[i] = patty[i-1] * 2 + 1;
        burger[i] = burger[i-1] *2 + 3;
        // cout << patty[i] << " " << burger[i] << endl;
    }
    cout << dfs(n, x, patty, burger) << endl;
    return 0;
}


