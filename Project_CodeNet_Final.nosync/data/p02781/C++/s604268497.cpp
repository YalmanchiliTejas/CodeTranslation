#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <stack>
#include <cctype>
#include <cmath>
#include <set>

using namespace std;

/* typedef */

typedef long long ll;

/* constant */

const int INF = 1 << 30;
const int MAX = 1000000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */

/* function */
ll calc(int x, int k);
ll comb(int x, int k);

/* main */
int main(){

    string N; cin >> N;
    int K; cin >> K;

    ll ans = 0;

    int digit = N.size();
    for (int i = 0; i < N.size() && K > 0; i++) {
        int a_i = N[i] - '0';
        //cout << "a_i : " << a_i << '\n';
        digit--;
        //cout << "digit : " << digit << '\n';
        if (a_i == 0) {
            continue;
        }
        if (K == 1) {
            ans += a_i;
        }
        if (K >= 1) {
            //cout << calc(digit, K) << '\n';
            ans += calc(digit, K);
        }
        a_i--;
        if (a_i) {
            if (K >= 2) {
                // cout << a_i * calc(digit, K-1) << '\n';
                ans += a_i * calc(digit, K-1);
            }
        }
        K--;
    }

    cout << ans << '\n';

    return 0;
}


ll calc(int x, int k) {

    return comb(x, k) * pow(9, k);
}

ll comb(int x, int k) {
    
    ll ret = 1;
    for (ll i = 1; i <= k; i++) {
        ret *= x - (i - 1);
        ret /= i;
    }
    return ret;

}
