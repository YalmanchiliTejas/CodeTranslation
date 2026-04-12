#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    int a[100010];
    for(int i = 0; i<N; ++i) cin >> a[i];
    // a1 > a2 < a3 > a4 < a5 > a6 < a7 (> a8)
    // sum = a1-a2 + a3-a2 + a3-a4 + a5-a4 + a5-a6 + a7-a6 + (a7-a8)
    // sum = a1 - 2*a2 + 2*a3 - 2*a4 + 2*a5 - 2*a6 + a7(*2 - a8)
    sort(a, a + N);

    ll ans = 0;
    if(N % 2 == 0){ // a1 > a2 < a3 ... > aN
        ans -= a[N/2-1]; // most large num of subtracted
        ans += a[N/2]; // most small num of added
        for(int i=0    ; i < N/2-1; ++i) ans -= a[i] * 2;
        for(int i=N/2+1; i < N    ; ++i) ans += a[i] * 2;
    } else {
        // 1, a1 > a2 < a3 ... < aN
        ll ans1 = 0;
        for(int i=0    ; i < N/2; ++i) ans1 -= a[i] * 2;
        ans1 += a[N/2  ];
        ans1 += a[N/2+1];
        for(int i=N/2+2; i < N  ; ++i) ans1 += a[i] * 2;

        // 2, a1 < a2 > a3 ... > aN
        ll ans2 = 0;
        for(int i=0    ; i < N/2-1; ++i) ans2 -= a[i] * 2;
        ans2 -= a[N/2-1];
        ans2 -= a[N/2  ];
        for(int i=N/2+1; i < N    ; ++i) ans2 += a[i] * 2;

        ans = max(ans1, ans2);
    }
    cout << ans << '\n';
    return 0;
}