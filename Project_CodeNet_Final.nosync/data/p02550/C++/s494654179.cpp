#include<bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve() {
    ll N, X, M;
    cin >> N >> X >> M;
    set<ll> visited;
    vector<ll> v;
    visited.emplace(X);
    v.emplace_back(X);
    ll prev = X, seed = X;
    while (true) {
        ll me = (prev * prev) % M;
        if (visited.count(me))
        {
            seed = me;
            break;
        }
        v.emplace_back(me);
        visited.emplace(me);
        prev = me;
    }

    ll sum = 0;
    if (N <= (int)v.size()) {
        for (int i = 0; i < N; ++i) sum += v[i];
    }
    else
    {
        int i = 0;
        for (; i < (int)v.size(); ++i) {
            if (v[i] == seed) {
                break;
            }
            sum += v[i];
            N--;
        }
        v.erase(v.begin(), v.begin() + i);
        ll ts = accumulate(v.begin(), v.end(), 0ll);
        ll f = N / (int)v.size();
        ll r = N % (int)v.size();
        sum += f * ts;
        for (int i = 0; i < r; ++i) sum += v[i];
    }
    cout << sum << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }
}
