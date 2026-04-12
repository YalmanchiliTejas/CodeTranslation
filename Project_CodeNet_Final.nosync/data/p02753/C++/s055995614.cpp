#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

// π M_PI
// deg = rad*180/M_PI

int main() {
    string s;
    cin >> s;
    if ( s[0] == s[1] && s[1] == s[2] ) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
