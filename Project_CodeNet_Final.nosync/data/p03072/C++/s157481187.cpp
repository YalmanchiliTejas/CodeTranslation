#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#define rep(i, l, r) for (ll i = (l); i <= (r); i++)
#define irep(i, r, l) for (ll i = (r); i >= (l); i--)
#define vec(t) vector<int>

using namespace std;
using ll = long long;
using veci = vec(int);
using vecll = vec(ll);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    veci H(N);
    rep(i, 0, N - 1) cin >> H[i];
    reverse(H.begin(), H.end());
    int c = 0;
    int ma = H[N - 1];
    irep(i, N - 1, 0) {
        if (H[i] >= ma) {
            c++;
        }
        ma = max(ma, H[i]);
    }

    cout << c << endl;
}