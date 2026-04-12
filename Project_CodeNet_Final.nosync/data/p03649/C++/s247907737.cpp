#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    ll res = 0;
    ll add = 0;
    bool loop = true;
    while(loop) {
        loop = false;
        for(int i = 0; i < N; ++i) {
            res += v[i] / N;
            add += v[i] / N;
            v[i] = v[i] - N * (v[i] / N) - v[i] / N;
        }
        for(int i = 0; i < N; ++i) {
            v[i] += add;
            loop |= v[i] > N - 1;
        }
        add = 0;
    }
    cout << res << endl;
}
