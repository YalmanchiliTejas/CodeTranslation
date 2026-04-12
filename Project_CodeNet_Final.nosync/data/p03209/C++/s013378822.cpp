#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<ll> a(55), p(55);
/* function */
ll f(ll n, ll x) {
    if (n == 0) {
        if (x <= 0) return 0;
        else return 1;
    }
    else if (x <= 1 + a[n - 1]) { return f(n - 1, x - 1); }
    else return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
}
/* main */
int main(){
    ll N, X;
    cin >> N >> X;
    a[0] = 1, p[0] = 1;
    for (int i = 0; i < N; i++) {
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }
    cout << f(N, X) << '\n';
}
