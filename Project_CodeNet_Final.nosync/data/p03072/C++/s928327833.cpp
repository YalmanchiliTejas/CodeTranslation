#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>

typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int h[n];
    REP(i, n) cin >> h[i];

    int cnt = 1;
    FOR(i, 1, n) {
        bool flag = true;
        REP(j, i) {
            if (h[j] > h[i]) flag = false;
        }
        if (flag) cnt++;
    }
    cout << cnt << endl;

    return 0;
}
