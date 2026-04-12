#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 100005;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
int K, N;
/* function */
/* main */
int main(){
    cin >> N >> K;
    ll ans = 0;
    for (int x = 1; x <= N; x++) {
        int r = N % x;
        int p = N / x;
        ans += p * max(0, x - K) + max(0, r - K + 1);
    }
    if (K == 0) {
        ans -= N;
    }
    cout << ans << '\n';
}
