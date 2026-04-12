#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N, X;
ll SIZE[52];
ll P[52];

ll f(ll n, ll x) {
    if(n == 0) return 1;
    if(x == 1) return 0;
    if(x <= SIZE[n-1] + 1) return f(n-1, x-1);
    if(x == SIZE[n-1] + 2) return 1 + P[n-1];
    if(x < SIZE[n]) return P[n-1] + 1 + f(n-1, x - SIZE[n-1] - 2);
    return P[n];
}

int main() {
    //cout.precision(10);
    cin >> N >> X;
    SIZE[0] = 1;
    P[0] = 1;
    for(int i = 1; i <= N; i++) {
        SIZE[i] = 3 + 2 * SIZE[i-1];
        P[i] = 1 + 2 * P[i-1];
    }
    cout << f(N, X) << endl;
    return 0;
}
