#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
const ll N = 123456;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n , k;
    cin >> n >> k;

    ll total = n * n;

    if(k == 0) {
        cout << total << endl;
    }
    else {
        ll sum = 0;
        rep(i , 1 , n) {
            if(i - 1 <= k - 1) {
                sum += n;
                //cout << i << " less " << n << endl;
                continue;
            }
            ll extra = (i - k);
            ll div = n / i;
            ll rem = n % i;
            sum += (i - extra) * div;
            sum += min(k - 1 , rem);
            //cout << i << " more " << (n - extra) * div + min(k - 1 , rem) << endl;
        }
        cout << total - sum << endl;
    }
    return 0;
}
