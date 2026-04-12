#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll N, X, M;
    cin >> N >> X >> M;
    vector<int> f(M, -1);
    ll ans = 0;
    ll A = X;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        if (f[A] == -1) {
            ans += A;
            f[A] = i;
            v.push_back(A);
            A = (A*A) % M;
        }
        else {
            ll l = N-i;
            ll s = 0;
            ll k = l % (i-f[A]);
            for (int j = f[A]; j < i; j++) {
                s += v[j];
                if (j < f[A]+k) {
                    ans += v[j];
                }
            }
            ans += s*(l/(i-f[A]));
            break;
        }
    }
    cout << ans << endl;
}