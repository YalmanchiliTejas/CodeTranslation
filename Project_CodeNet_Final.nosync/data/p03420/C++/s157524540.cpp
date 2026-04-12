#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

// .##.##.##.#
void solve(lint n,lint k) {
    /*
    lint ansa = 0;
    for (int a=1; a<=n; a++) {
        for (int b=1; b<=n; b++) {
            if (a%b >= k) ansa ++;
        }
    }
    */
    //cout << ansa << endl;

    lint ans = 0;
    if (k == 0) {
        ans = n*n;
    }
    else {
        for (lint b=1; b <= n; b++) {
            if (b <= k) continue;
            lint t = b-k;
            ans += n/b * t;
            lint c = n%b + 1;
            ans += max(c-k,(lint)0);
            
        }
    }
    cout << ans << endl;
    //if (ans != ansa) {
    //    cout << n << ' ' << k << endl;
    //}

}

int main() {
    lint n,k; cin >> n >> k;
    solve(n,k);
}