//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vi a(n);
    ll ave = 0LL;
    rep(i, n) {
        cin >> a[i];
        ave += a[i];
    }

    vi ap(n/2), am(n/2);
    ave /= n;
    ll ans = 0LL;

    sort(a.begin(), a.end());

    rep(i, n/2) {
        am[i] = a[i];
        ans += 2*ave - 2*a[i];
    }

    reverse(a.begin(), a.end());

    rep(i, n/2) {
        ap[i] = a[i];
        ans += 2*a[i] - 2*ave;
    }

    reverse(am.begin(), am.end());
    reverse(ap.begin(), ap.end());


    ans -= ap[0] - am[0];
    
    if(1&n) {
        ans += max(a[n/2] -am[0], ap[0]-a[n/2]);
    }

    cout << ans << endl;

}