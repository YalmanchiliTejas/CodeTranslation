#include <iostream>

using namespace std;
typedef long long ll;

ll n, x;
ll bn[55];
ll pn[55];

ll solve(ll m, ll k){
//    cout << m << " " << k << endl;
    if(m == 0)
        return 1;

    if(bn[m] <= k){
        return pn[m];
    }

    ll ret = 0;
    k--;
    if(k > 0) {
        if (bn[m - 1] > k) {
            ret += solve(m - 1, k);
        } else {
            ret += pn[m - 1];
            k -= bn[m - 1];

            if(k > 0) {
                k--;
                ret++;

                if (k > 0) {
                    if (bn[m - 1] > k) {
                        ret += solve(m - 1, k);
                    } else {
                        ret += pn[m-1];
                        k -= bn[m-1];
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
    cin >> n >> x;
    bn[0] = 1;
    pn[0] = 1;
    for(int i = 1; i < 55; i++){
        bn[i] = bn[i-1]*2 + 3;
        pn[i] = pn[i-1]*2 + 1;
    }

    cout << solve(n, x) << endl;
}
