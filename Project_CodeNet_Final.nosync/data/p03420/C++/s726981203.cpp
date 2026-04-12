//
//  Created by Ruslan Jankurazov.
//  Copyright © 2018 Ruslan Jankurazov. All rights reserved.
//

#pragma GCC optimize("Ofast")

#include "bits/stdc++.h"

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define f first
#define s second
#define uint unsigned int

using namespace std;


int main() {
#define FILE_INPUT 0
#define FILE ""
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if FILE_INPUT == 1
#warning "FREOPEN is on"
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
#endif
#endif
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k == 0) {
        cout << n*n;
        return 0;
    }
    for (ll i = 1; k + i <= n; ++i) {
        ll e = k + i;
        ans += (n/e)*i + (n%e >= k?n%e - k + 1:0);
    }
    cout << ans;
    return 0;
}
