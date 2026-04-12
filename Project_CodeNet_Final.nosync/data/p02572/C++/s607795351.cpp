#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main() {
    ll N; 
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
        sum %= MOD;
    }
    ll res = 0;
    for (ll i = 0; i < N; ++i) {
        sum -= A[i];
        if (sum < 0) sum += MOD;
        res += A[i] * sum;
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
