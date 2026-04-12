#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> patty(51);
vector<ll> atsumi(51);

ll dfs(int n, ll x) {
        if (x <= 0) {
            return 0;
        } else if (n == 0) {
            return 1;
        } else if (x >= atsumi[n]) {
            return patty[n];
        } else if (x >= atsumi[n-1] + 2) {
            return patty[n-1] + dfs(n-1, x - atsumi[n-1] - 2) + 1;
        } else {
            return dfs(n-1, x-1);
        }
    }

int main() {
    ll N, X; cin >> N >> X;
    patty[0] = 1;
    for (int i = 1; i < 51; i++) patty[i] = 2 * patty[i-1] + 1;
    atsumi[0] = 1;
    for (int i = 1; i < 51; i++) atsumi[i] = 2 * atsumi[i-1] + 3;
    cout << dfs(N, X) << endl;
}
