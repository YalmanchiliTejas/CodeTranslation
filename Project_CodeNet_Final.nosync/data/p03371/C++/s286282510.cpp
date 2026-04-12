#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll min_cost = INF;
    for(int k=0; k<=100000; k++) {
        ll cost = 2*C*k + max(0, X-k) * A + max(0, Y-k) * B;
        min_cost = min(min_cost, cost);
    }
    cout << min_cost << endl;
}