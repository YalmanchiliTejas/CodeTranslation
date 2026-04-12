#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    ll ans = 0, sum = 0;
    vector<ll> cnt(N);
    bool loop = true;
    while (loop) {
        loop = false;
        for (int i = 0; i < N; i++) cnt[i] = v[i] / N;
        sum = accumulate(cnt.begin(), cnt.end(), 0LL);
        ans += sum;
        for (int i = 0; i < N; i++) {
            v[i] -= cnt[i] * N;
            v[i] += (sum - cnt[i]);
            if (v[i] >= N) loop = true;
        }
    }
    cout << ans << '\n';
}
