#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> a(51), p(51);

ll baga(ll N, ll X) {
    if (N == 0) return X <= 0 ? 0 : 1;
    else if (X <= (1 + a[N-1])) return baga(N-1, X-1);
    else return p[N-1] + 1 + baga(N-1, X - 2 - a[N-1]);
}

int main() {
    ll N, X;
    cin >> N >> X;


    a[0] = 1; p[0] = 1;
    for (int i = 1; i < N; i++) {
        a[i] = a[i-1]*2 + 3;
        p[i] = p[i-1]*2 + 1;
    }


    ll res = baga(N, X);

    cout << res << endl;

}
