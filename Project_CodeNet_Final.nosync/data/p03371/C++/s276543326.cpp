#include <bits/stdc++.h>

#define INF 1e9
#define LLINF 1e12
using namespace std;

#define REPR(i, n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int maxi = 2 * 1e5;
    ll minCost = LLINF;
    REP(boughtABpizza, maxi + 1) {
        ll cost = boughtABpizza * C;
        int kumiawasePizza = boughtABpizza / 2;

        cost += max(0, (X - kumiawasePizza) * A);
        cost += max(0, (Y - kumiawasePizza) * B);
        chmin(minCost,cost);
    }
    cout << minCost << endl;
    return 0;
}
