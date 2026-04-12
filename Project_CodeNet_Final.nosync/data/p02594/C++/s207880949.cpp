//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define in(x, l, r) (ll)(l) <= (x) && (x) < (ll)(r)

int main() {
    vector<int> v(250000000,0);
    int X;
    cin >> X;
    if (X >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
