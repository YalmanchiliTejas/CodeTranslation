#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime> 
#include <memory.h>
#include <assert.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18 + 1;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for(auto &e : A) cin >> e;

    sort(A.begin(), A.end());

    ll ans = 0;
    if (N%2 == 0) {
        // p1 >= p2 <= p3 >= p4 ...
        // p1 + 2 * (p3+p5...) - 2 * (p2+p4+...) - pn
        // = 2 * (p1+p3+p5+...) - 2 * (p2+p4+...+pn) - p1 + pn
        // p1: 中央値、pn：中央値以下で最大値
        // (p2+p4+...) : 中央値より小さい区間の和
        // (p3+p5+...) : 中央値より大きい区間の和
        int k = N/2;
        for(int i = 0; i < k; ++i) ans -= 2LL * A[i];
        for(int i = k; i < 2*k; ++i) ans += 2LL * A[i];
        ans -= A[k];
        ans += A[k-1];
    } else {
        // p1 >= p2 <= p3 >= p4 ...
        // p1 + pn + 2 * (p3+p5...) - 2 * (p2+p4+...)
        // p1: 中央値、pn：中央値以上で最大値
        // (p2+p4+...) : 中央値より小さい区間の和
        // (p3+p5+...) : 中央値より大きい区間の和
        ll ret1 = 0;
        int k = N/2;
        for(int i = 0; i < k; ++i) ret1 -= 2LL * A[i];
        ret1 += A[k];
        ret1 += A[k+1];
        for(int i = k+2; i < k*2+1; ++i) ret1 += 2LL * A[i];

        // p1 <= p2 >= p3 <= p4 ...
        // 2 * (p2+p4+...) - (p3+p5...) - p1 - pn
        // p1: 中央値、pn：中央値以下で最大値
        // (p2+p4+...) : 中央値より大きい区間の和
        // (p3+p5+...) : 中央値より小さい区間の和
        ll ret2 = 0;
        for(int i = 0; i < k-1; ++i) ret2 -= 2LL * A[i];
        ret2 -= A[k-1];
        ret2 -= A[k];
        for(int i = k+1; i < 2*k+1; ++i) ret2 += 2LL * A[i];

        ans = max(ret1, ret2);
    }

    cout << ans << endl;

    return 0;
}