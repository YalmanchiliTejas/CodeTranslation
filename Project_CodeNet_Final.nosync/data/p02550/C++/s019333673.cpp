#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    int x, m;
    cin >> n >> x >> m;

    vector<bool> al(m, false);
    list<int> q;
    ll a = x;
    int c = 0;

    q.emplace_back(a);
    al.at(a) = true;
    c++;

    while(true) {
        a = a * a % m;
        if(al.at(a)) {
            break;
        } else {
            q.emplace_back(a);
            al.at(a) = true;
            c++;
        }
    }

    int d = 0;
    ll sum0 = 0;
    auto itr = q.begin();
    while(*itr != a) {
        sum0 += *itr;
        itr++;
        d++;
    }
    int per = c - d;

    auto itr2 = itr;
    ll sump = 0;
    rep(i, per) {
        sump += *itr2;
        itr2++;
    }

    ll ans = sum0 + (n - d) / per * sump;
    rep(i, (n - d) % per) {
        ans += *itr;
        itr++;
    }

    printf("%lld\n", ans);

    return 0;
}