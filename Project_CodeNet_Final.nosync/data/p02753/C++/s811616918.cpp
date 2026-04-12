#include <bits/stdc++.h>
using namespace std;


struct unionFind {
    vector<int> parent;
    unionFind(int n): parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    };

    int root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) parent[y] = x;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;

    if (s == "AAA" or s == "BBB") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }





    return 0;
}

