#include <bits/stdc++.h>
using namespace std;

struct Node {
    int64_t value;
    int64_t prop_value;

    Node (int64_t _value, int64_t _prop_value) {
        value = _value;
        prop_value = _prop_value;
    }
};

struct Aint {
    int n;
    vector<Node> tree;

    Aint(int _n) {
        n = _n;
        tree = vector<Node> (4 * (n + 1), Node(numeric_limits<int64_t> :: min() / 2, 0));
    }

    void propagate(int idx) {
        if (tree[idx].prop_value == 0)
            return;
        tree[idx].value += tree[idx].prop_value;
        for (int d = 0; d < 2; d += 1)
            if (2 * idx + d < (int) tree.size())
                tree[2 * idx + d].prop_value += tree[idx].prop_value;
        tree[idx].prop_value = 0;
    };

    int64_t getMax() {
        return tree[1].value;
    }

    void add(int node, int st, int dr, int left, int right, int64_t delta) {
        if (st >= left and dr <= right) {
            tree[node].prop_value += delta;
            propagate(node);
            return;
        }
        
        int mid = (st + dr) / 2;
        propagate(node);

        if (left <= mid)
            add(2 * node, st, mid, left, right, delta);
        if (right > mid)
            add(2 * node + 1, mid + 1, dr, left, right, delta);

        propagate(2 * node);
        propagate(2 * node + 1);
        tree[node].value = max(tree[2 * node].value, tree[2 * node + 1].value);
    }

    void update(int node, int st, int dr, int poz, int64_t new_value) {
        if (st == dr) {
            tree[node].value = new_value;
            return;
        }
        
        int mid = (st + dr) / 2;
        propagate(node);

        if (poz <= mid)
            update(2 * node, st, mid, poz, new_value);
        if (poz > mid)
            update(2 * node + 1, mid + 1, dr, poz, new_value);
        
        propagate(2 * node);
        propagate(2 * node + 1);
        tree[node].value = max(tree[2 * node].value, tree[2 * node + 1].value);
    }

    int get(int node, int st, int dr, int poz) {
        propagate(node);
        if (st == dr)
            return tree[node].value;
        int mid = (st + dr) / 2;
        if (poz <= mid)
            return get(2 * node, st, mid, poz);
        return get(2 * node + 1, mid + 1, dr, poz);
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> x(m, 0), y(m, 0), cost(m, 0);
    
    vector<vector<int>> in(n + 1), out(n + 1);

    for (int i = 0; i < m; i += 1) {
        cin >> x[i] >> y[i] >> cost[i];
        in[x[i]].push_back(i);
        out[y[i]].push_back(i);
    }
    
    vector<int64_t> dp(n + 2, 0);
    
    Aint T(n + 2);
    T.update(1, 1, n + 1, 1, 0);
    
    for (int i = 2; i <= n + 1; i += 1) {
        for (int idx : in[i - 1]) {
            T.add(1, 1, n + 1, 1, x[idx], cost[idx]);
        }
        
        dp[i] = T.getMax();
        T.update(1, 1, n + 1, i, dp[i]);

        for (int idx : out[i - 1])
            T.add(1, 1, n + 1, 1, x[idx], -cost[idx]);   
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}