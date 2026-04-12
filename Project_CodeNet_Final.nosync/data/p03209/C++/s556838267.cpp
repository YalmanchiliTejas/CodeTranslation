#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <climits>
#include <unordered_map>
#include <queue>


#define rep(i, n) for(int i = 0, end = (int)(n); i < end; i++)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

inline int ctoi(char c) {
    return (int)(c -'0');
}

// ----------------------------------------------------------

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> berger(n+1);
    vector<ll> paty(n+1);
    berger[0] = 1;
    paty[0] = 1;
    rep(i, n) {
        berger[i+1] = berger[i] * 2 + 3;
        paty[i+1] = paty[i] * 2 + 1;
    }
    ll dansu = n;
    ll ans = 0;
    while (x > 0) {
        if (dansu == 0) {
            ans += 1;
            break;
        } 
        if (x==berger[dansu]) {
            ans += paty[dansu];
            break;
        } else if (berger[dansu - 1] + 2 < x) {
            ans += paty[dansu - 1] + 1;
            x -= berger[dansu - 1] + 2;
            --dansu;
            continue;
        } else if (berger[dansu - 1] + 2 == x) {
            ans += paty[dansu - 1] + 1;
            break;
        } else if (x != 1) {
            --dansu;
            x -= 1;
            continue;
        } else {
            break;
        }
    }
    cout << ans <<  endl;
    return 0;
}