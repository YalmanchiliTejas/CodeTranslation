#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, n) REP(i, 0, n)
#define REP(i, a, n) for(int i=(a); i<(n); i++)

int N;
ll X;

ll dfs(ll x, int n) {
    if(x < n) return 0;
    if(n == 0) return 1;
    ll m = pow(2, n+2)-3;
    if(x > m-n) return pow(2, n+1) - 1;
    if(x < m/2) return dfs(x-1, n-1);
    else if(x > m/2) return pow(2, n) + dfs(x-m/2-1, n-1);
    else return pow(2, n);
}

int main() {
    cin >> N >> X;
    cout << dfs(X-1, N) << endl;
}
