#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int n;
vector<ll> a, c;

void input() {
    cin >> n;
    rep(i, n) {
        ll x;
        cin >> x;
        a.push_back(-x);
    }
}

int main() {
    input();
    for (ll x : a) {
        auto itr = upper_bound(c.begin(), c.end(), x);
        if (itr == c.end()) c.push_back(x);
        else c[itr-c.begin()] = x;
    }
    cout << c.size() << endl;
}
