#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
const int N = 123456;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n , x;
    cin >> n >> x;

    vector < ll > a;
    vector < ll > p;
    a.push_back(1);
    p.push_back(1);

    for(int i = 1 ; i <= 50 ; i++) {
        a.push_back(a[i - 1] * 2 + 3LL);
        p.push_back(p[i - 1] * 2 + 1LL);
    }

    ll ans = 0;
    while(x > 0) {
        while(x < a[n] && x > 0) {
            x--;
            n--;
        }
        if(x == 0) break;
        x -= a[n];
        ans += p[n];
        if(x > 0) {
            x--;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
