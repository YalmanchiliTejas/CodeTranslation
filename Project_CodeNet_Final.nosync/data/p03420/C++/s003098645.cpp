#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <deque>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e6 + 10, S2 = 1e7 * 2, MOD = 1e9 + 7, INF = 1e9 * 1e9 + 100;

ll check(ll vl, ll a, ll b) {
    /*vector<ll> vec1, vec2;
    for (int i = 1; i <= vl; i++) {
        if (i != a) vec1.push_back(i);
    }

    for (int i = 1; i <= vl; i++) {
        if (i != b) vec2.push_back(i);
    }
    if (vec1.size() < vl) vec1.push_back(vl + 1);
    if (vec2.size() < vl) vec2.push_back(vl + 1);
*/
    ll q = 0;
    ll q2 = 0, vl1 = (vl - 1) / 2, vl2 = (vl - 1) / 2;

    if (vl == 14) {
        cout << "";
    }
    if (vl % 2 != 0) {
        vl1 = (vl / 2) + 1;
        vl2 = vl1;
        if (vl1 >= a) vl1++;
        if (vl2 >= b) vl2++;
        q2 = vl1 * vl2;
    }
    else {
        vl1 = (vl - 1) / 2 + 1, vl2 = vl1 + 1;
        if (vl1 >= a) vl1++;
        if (vl2 >= b) vl2++;
        if (vl2 < b) {
            ll q = b - vl2, v1 = vl1, v2 = vl2;
            v1 -= q;
            v2 = b + 1;
            q2 = v2 * v1;
        }
        if (vl1 < a) {
            ll q = a - vl1, v1 = vl1, v2 = vl2;
            v1 = a + 1;
            v2 -= q;
            q2 = max(v2, v2 * v1);
        }
        q2 = max(q2, vl2 * vl1);
        vl1 = (vl - 1) / 2 + 1, vl2 = vl1 + 1;
        vl1--;
        //if (vl2 < b) {
        //    ll q = b - vl2, v1 = vl1, v2 = vl2;
        //    v1 -= q;
        //    v2 = b + 1;
        //    q2 = v2 * v1;
        //}
        //if (vl1 < a) {
        //    ll q = a - vl1, v1 = vl1, v2 = vl2;
        //    v1 = a + 1;
        //    v2 -= q;
        //    q2 = max(v2, v2 * v1);
        //}
        if (vl1 >= a) vl1++;
        if (vl2 >= b) vl2++;
        
        q2 = max(q2, vl2 * vl1);
    }

   /* for (int i = 0; i < vl; i++) q = max(q, vec1[i] * vec2[vl - i - 1]);
*//*
    if (q != q2) {
        cout << "sdhfb";
    }*/
    q = q2;
    return q;
}

int main() {
    fastInp;

    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    for (int i = k + 1; i <= n; i++) {
        ll l = -1, r = n + 1;
        ll am = (i - k);
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll val = (mid / am) * i + (k + mid % am);
            if (val <= n) {
                l = mid;
            } else{
                r = mid;
            }
        }
        if (k == 0) ans--;
        ans += l + 1;
    }

    cout << ans;
    return 0;
}

