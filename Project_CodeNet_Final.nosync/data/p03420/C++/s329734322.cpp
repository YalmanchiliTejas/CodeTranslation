#include <bits/stdc++.h>

#define fr first
#define sc second
#define OK puts("OK");
#define pb push_back
#define mk make_pair
#define ll long long
using namespace std;


const int inf = (int)1e9 + 7;
const int N = (int)1e5 + 7;

ll a,b;
ll ans;
ll p[N];

 main () {
    cin >> a >> b;

    if (b == 0) {
        cout << a * 1ll * a << endl;
        return 0;
    }
    for (int i = b + 1; i <= a; i ++) {
        for (int j = i; j <= a; j += i)
            p[j] ++;
    }
    for (int i = b + 1; i <= a; i ++)
        p[i] += p[i - 1];

    for (int i = b; i <= a; i ++) {
        ans += (a - i);
        ll x = i - b;

        ans += (i - (p[i] - p[x]) - b);
    }
    cout << ans << endl;
}
