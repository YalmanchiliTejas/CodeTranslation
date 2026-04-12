#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

#ifndef INPUTS_DIR
#define INPUTS_DIR "./"
#endif

struct UnionFind {
    vector<int> data;

    UnionFind(int size) : data(size, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool findSet(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};

void solve(ll N, vector<ll> x, vector<ll> y) {
    vector<pair<ll, ll> > ps;
    for (int i = 0; i < N; i++) ps.push_back({x[i], y[i]});
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    N = ps.size();
    map<pair<ll, ll>, int> conv;
    for (int i = 0; i < N; i++) conv[ps[i]] = i;
    vector<pair<ll, pair<int, int> > > es;
    {
        sort(ps.begin(), ps.end(), [&](pair<ll, ll> a, pair<ll, ll> b) { return a.first < b.first; });
        for (int i = 0; i + 1 < ps.size(); i++)
            es.push_back({ps[i + 1].first - ps[i].first, {conv[ps[i]], conv[ps[i + 1]]}});
    }
    {
        sort(ps.begin(), ps.end(), [&](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; });
        for (int i = 0; i + 1 < ps.size(); i++)
            es.push_back({ps[i + 1].second - ps[i].second, {conv[ps[i]], conv[ps[i + 1]]}});
    }
    sort(es.begin(), es.end());
    UnionFind uf(N);
    long long ans = 0;
    for (auto &e : es) {
        ans += uf.unionSet(e.second.first, e.second.second) * e.first;
    }
    cout << ans << endl;

}


void main_(istream &cin) {
    ll N;
    cin >> N;
    vector<ll> y(N - 1 + 1);
    vector<ll> x(N - 1 + 1);
    for (int i = 0; i <= N - 1; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    solve(N, x, y);
}

int main() {
#ifdef INTELLIJ
    ifstream ifs(string(INPUTS_DIR) + "in_1.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}



