#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    string s;
    ll K;
    cin >> s;
    cin >> K;
    ll len = s.size();
    ll ans = 0;
    if (K == 1){
        REP(i, len) rep(j, 1, 10){
            string ss(len, '0');
            ss[i] = '0' + j;
            if (ss <= s) ans++;
        }
    }else if (K == 2){
        rep(i, 0, len) rep(j, i + 1, len)rep(a1, 1, 10)rep(a2, 1, 10){
                string ss(len, '0');
                ss[i] = '0' + a1;
                ss[j] = '0' + a2;
                if (ss <= s) ans++;
            }
    }else {
        if (len > 3) {
            ans += (len - 1) * (len - 2) * (len -3) / 6 * 9 * 9 * 9;
            ans += (s[0] - '1') * (len - 1) * (len - 2) / 2 * 9 * 9;
            rep(i, 1, len) rep(j, i + 1, len)rep(a1, 1, 10)rep(a2, 1, 10){
                string ss(len, '0');
                ss[0] = s[0];
                ss[i] = '0' + a1;
                ss[j] = '0' + a2;
                if (ss <= s) ans++;
            }
        }else{
                ans += (s[0] - '1') * (len - 1) * (len - 2) / 2 * 9 * 9;
                rep(a1, 1, 10)rep(a2, 1, 10){
                string ss(len, '0');
                ss[0] = s[0];
                ss[1] = '0' + a1;
                ss[2] = '0' + a2;
                if (ss <= s) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}