#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll f(vector<ll>& l, vector<ll>& p, int n, ll x) {
    if (n == 0)
        return x <= 0 ? 0 : 1;
    if (x - 1 <= l[n-1])
        return f(l, p, n-1, x-1);
    return p[n-1] + 1 + f(l, p, n-1, x-l[n-1]-2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    ll X; cin >> X;
    vector<ll> l(N), p(N);
    l[0] = p[0] = 1;
    for (int i = 1; i < N; i++) {
        l[i] = l[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }
    cout << f(l, p, N, X) << "\n";
}