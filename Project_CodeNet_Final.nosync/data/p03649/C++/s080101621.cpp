#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, a, count = 0;
    cin >> N;
    priority_queue<ll> pq;
    rep(i, N) {
        cin >> a;
        pq.push(a);
    }
    while (true) {
        a = pq.top();
        pq.pop();
        if (a <= N - 1 - count) {
            cout << count << endl;
            break;
        }
        ll d = (a + 1 + count) / (N + 1);
        a -= d * (N + 1);
        count += d;
        pq.push(a);
    }
}