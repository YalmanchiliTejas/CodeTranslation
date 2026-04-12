#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 998244353;

int ks[3001];

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> As(N);
    for (auto& A : As) {
        cin >> A;
    }
    ll s = 0;
    memset(ks, 0, sizeof(ks));
    ks[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = S; j >= As[i]; j--) {
            ks[j] = (ks[j] + ks[j - As[i]]) % MOD;
        }
        s = (s + ks[S]) % MOD;
        ks[0]++;
    }
    cout << s << endl;
}