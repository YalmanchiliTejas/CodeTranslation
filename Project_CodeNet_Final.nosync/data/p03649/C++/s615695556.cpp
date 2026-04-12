#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N; cin >> N;
    priority_queue<ll> q;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x; q.emplace(x);
    }
    ll res = 0;
    while (q.size()) {
        ll x = q.top(); q.pop();
        ll t = (x + res) / N;
        if (t == 0) continue;
        res += t;
        q.push(x - t * (N+1));
    }
    cout << res << endl;
}