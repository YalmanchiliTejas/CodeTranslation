#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

struct Edge {
    ll from;
    ll to;
    ll cost;
    Edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
};

vector<ll> union_find, rnk;

ll group_of(ll idx) {
    if (union_find[idx] == idx) {
        return idx;
    } else {
        return (union_find[idx] = group_of(union_find[idx]));
    }
}


void unite(ll from, ll to) {
    if (rnk[from] < rnk[to]) {
        union_find[from] = to;
    } else {
        union_find[to] = from;
        if (rnk[from] == rnk[to]) {
            rnk[from]++;
        }
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> xidx(N), yidx(N);
    union_find = vector<ll>(N);
    rnk = vector<ll>(N, 0);
    for (ll i = 0; i < N; i++) {
        xidx[i] = i;
        yidx[i] = i;
        union_find[i] = i;
    }

    vector<p> town(N);
    for (ll i = 0; i < N; i++) {
        cin >> town[i].first >> town[i].second;
    }
    
    sort(xidx.begin(), xidx.end(), [&town](ll left, ll right) {
        p l = town[left];
        p r = town[right];
        return l.first < r.first;
    });

    sort(yidx.begin(), yidx.end(), [&town](ll left, ll right) {
        p l = town[left];
        p r = town[right];
        return l.second < r.second;
    });

    vector<Edge> E;
    for (ll i = 0; i < N - 1; i++) {
        ll d = town[xidx[i + 1]].first - town[xidx[i]].first;
        E.push_back(Edge(xidx[i], xidx[i + 1], d));
    }

    for (ll i = 0; i < N - 1; i++) {
        ll d = town[yidx[i + 1]].second - town[yidx[i]].second;
        E.push_back(Edge(yidx[i], yidx[i + 1], d));
    }

    sort(E.begin(), E.end(), [](Edge l, Edge r) {
        return l.cost < r.cost;
    });

    ll ans = 0;
    for (auto&& e : E) {
        ll from_group = group_of(e.from);
        ll to_group = group_of(e.to);
        if (from_group == to_group) {
            continue;
        }

        // cout << "add" << endl;

        ans += e.cost;
        unite(from_group, to_group);
        /*
        for (auto&& u : union_find) {
            cout << u << " ";
        }
        cout << endl;
        */
    }

    cout << ans << endl;
    return 0;
}

