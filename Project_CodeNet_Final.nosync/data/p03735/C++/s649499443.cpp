#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 100, INF = 1e9, MOD = 1e9 + 7;

vector<pair<ll, ll>> vec;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll brute() {
    ll pw = (1ll << vec.size());

    pair<ll, ll> ans[2];
    ans[0] = { -INF, 0 };
    ans[1] = { -INF, 0 };
    for (int i = 0; i < pw; i++) {
        pair<ll, ll> vals[2];
        vals[0] = { INF, -INF };
        vals[1] = { INF, -INF };
        for (int j = 0; j < vec.size(); j++) {
            if ((i >> j) & 1) {
                vals[0].first = min(vals[0].first, vec[j].first);
                vals[0].second = max(vals[0].second, vec[j].first);

                vals[1].first = min(vals[1].first, vec[j].second);
                vals[1].second = max(vals[1].second, vec[j].second);
            }
            else {
                vals[0].first = min(vals[0].first, vec[j].second);
                vals[0].second = max(vals[0].second, vec[j].second);

                vals[1].first = min(vals[1].first, vec[j].first);
                vals[1].second = max(vals[1].second, vec[j].first);
            }
        }

        if ((ans[0].second - ans[0].first) * (ans[1].second - ans[1].first) > (vals[0].second - vals[0].first) * (vals[1].second - vals[1].first)) {
            ans[0] = vals[0];
            ans[1] = vals[1];
        }
    }
    cout << "-----------------\n";
    cout << ans[0].first << " " << ans[0].second << " " << ans[1].first << " " << ans[1].second << " " << (ans[0].second - ans[0].first) * (ans[1].second - ans[1].first) << "\n";
    cout << "-----------------\n";
    return (ans[0].second - ans[0].first) * (ans[1].second - ans[1].first);
}

void rand_test() {
    ll n = rng() % 15;
    if (n <= 5) n += 5;

    vec.clear();
    cout << "-----------------\n";
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        ll u = rand() % 20, v = rand() % 20;
        cout << u << " " << v << "\n";
        vec.push_back({ u, v });
    }
}

void input() {
    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        vec.push_back({ u, v });
    }
}

ll sol() {
    pair<ll, ll> vals[2];
    ll ans = INT64_MAX;
    vals[0] = { INF, -INF };
    vals[1] = { INF, -INF };
    vector<pair<ll, ll>> vec2;
    multiset<ll> s1, s2;
    for (int i = 0; i < vec.size(); i++) {
        ll u = vec[i].first, v = vec[i].second;

        if (u > v) swap(u, v);

        vec2.push_back({ v, u });
        s1.insert(v);
        s2.insert(u);
    }

    sort(vec2.rbegin(), vec2.rend());

    for (int i = 0; i < vec2.size(); i++) {
        ll v = vec2[i].first, u = vec2[i].second;
        if ((((*s1.rbegin()) - (*s1.begin())) * ((*s2.rbegin()) - (*s2.begin()))) <= ans) {
            ans = (((*s1.rbegin()) - (*s1.begin())) * ((*s2.rbegin()) - (*s2.begin())));
            vals[0] = { (*s1.rbegin()), (*s1.begin()) };
            vals[1] = { (*s2.rbegin()), (*s2.begin()) };
        }

        s1.erase(s1.find(v));
        s2.erase(s2.find(u));

        s1.insert(u);
        s2.insert(v);

        if ((((*s1.rbegin()) - (*s1.begin())) * ((*s2.rbegin()) - (*s2.begin()))) <= ans) {
            ans = (((*s1.rbegin()) - (*s1.begin())) * ((*s2.rbegin()) - (*s2.begin())));
            vals[0] = { (*s1.rbegin()), (*s1.begin()) };
            vals[1] = { (*s2.rbegin()), (*s2.begin()) };
        }
    }

   /* cout << vals[0].first << " " << vals[0].second << " " << vals[1].first << " " << vals[1].second << " " << (vals[0].second - vals[0].first) * (vals[1].second - vals[1].first) << "\n";
    cout << "-----------------\n";*/
    return (vals[0].second - vals[0].first) * (vals[1].second - vals[1].first);
}

int main()
{
    fastInp;

    ll t;
    t = 1;

    while (t--) {
        input();
        ll q2 = sol();
        cout << q2;
    }
    
    return 0;
}