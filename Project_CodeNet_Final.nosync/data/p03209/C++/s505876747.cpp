#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 51;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<ll> cntP(MAX), height(MAX);
/* function */
void init() {
    cntP[0] = height[0] = 1;
    for (int i = 0; i < MAX - 1; i++) {
        cntP[i+1] = cntP[i] * 2 + 1;
        height[i+1] = 1 + height[i] + 1 + height[i] + 1;
    }
}
ll f(int n, ll x) {
    ll harf = height[n] / 2;
    if (x <= 0) return 0;
    if (n <= 0) return 1;
    if (x <= harf) return f(n - 1, x - 1);
    else return f(n - 1, min(x - harf - 1, harf)) + cntP[n - 1] + 1;
}
/* main */
int main(){
    int N;
    ll X;
    cin >> N >> X;
    init();
    cout << f(N, X) << '\n';
}
