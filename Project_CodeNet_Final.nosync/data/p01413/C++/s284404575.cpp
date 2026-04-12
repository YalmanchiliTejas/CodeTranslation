#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>

#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}

struct Product {
    ll weight;
    ll value;
};
ostream& operator<<(ostream& os, const Product& p)
{
    os << "(" << p.weight << "," << p.value
       << ")";
    return os;
}


int main()
{
    ll N, M, W, T;
    cin >> N >> M >> W >> T;
    const ll maximum = 1 << N;
    unordered_map<string, Product> products;
    for (ll i = 0; i < M; i++) {
        string s;
        cin >> s;
        ll v, p;
        cin >> v >> p;
        products[s] = Product{v, p};
    }
    using pii = pair<ll, ll>;
    vector<pii> pos(N);
    vector<vector<Product>> store(N);
    for (ll i = 0; i < N; i++) {
        ll L;
        cin >> L;
        cin >> pos[i].first >> pos[i].second;
        for (ll j = 0; j < L; j++) {
            string s;
            cin >> s;
            ll q;
            cin >> q;
            const Product& p = products.at(s);
            store[i].push_back(Product{p.weight, p.value - q});
        }
    }

    vector<vector<ll>> d(N, vector<ll>(N));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            d[i][j] = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
        }
    }

    vector<vector<Product>> prods(maximum);
    for (ll i = 0; i < maximum; i++) {
        for (ll j = 0; j < N; j++) {
            if (i & (1 << j)) {
                for (const auto& e : store[j]) {
                    prods[i].push_back(e);
                }
            }
        }
    }
    constexpr ll INF = 1LL << 60;
    vector<ll> value(maximum, 0);
    for (ll i = 0; i < maximum; i++) {
        const ll size = prods[i].size();
        vector<vector<ll>> dp(size + 1, vector<ll>(W + 1, -INF));
        dp[0][0] = 0;
        for (ll j = 0; j < size; j++) {
            for (ll w = 0; w <= W; w++) {
                if (w < prods[i][j].weight) {
                    dp[j + 1][w] = max(dp[j + 1][w], dp[j][w]);
                } else {
                    dp[j + 1][w] = max(dp[j + 1][w], max(dp[j][w], dp[j + 1][w - prods[i][j].weight] + prods[i][j].value));
                }
            }
        }
        ll maxi = -INF;
        for (ll w = 0; w <= W; w++) {
            maxi = max(maxi, dp[size][w]);
        }
        value[i] = maxi;
    }

    set<vector<ll>> st;
    vector<pii> tours;

    vector<ll> v(N);
    for (ll i = 0; i < N; i++) {
        v[i] = i;
    }
    do {
        ll dist = abs(pos[v[0]].first) + abs(pos[v[0]].second);
        ll mask = 0;
        vector<ll> sub;
        for (ll i = 0; i < N; i++) {
            sub.push_back(v[i]);
            mask += (1 << v[i]);
            if (st.find(sub) == st.end()) {
                st.insert(sub);
                const ll D = dist + abs(pos[v[i]].first) + abs(pos[v[i]].second);
                tours.push_back(make_pair(value[mask], D));
            }
            dist += ((i < N - 1) ? d[v[i]][v[i + 1]] : 0);
        }
    } while (next_permutation(v.begin(), v.end()));

    ll size = tours.size();
    vector<ll> prev(T + 1, -INF);
    vector<ll> table(T + 1, -INF);
    prev[0] = 0;
    for (ll i = 0; i < size; i++) {
        for (ll j = 0; j <= T; j++) {
            if (j < tours[i].second) {
                table[j] = max(table[j], prev[j]);
            } else {
                table[j] = max(table[j], max(prev[j], table[j - tours[i].second] + tours[i].first));
            }
        }
        prev = table;
        fill(table.begin(), table.end(), -INF);
    }
    ll maxi = -INF;
    for (ll i = 0; i <= T; i++) {
        maxi = max(maxi, prev[i]);
    }
    cout << maxi << endl;

    return 0;
}