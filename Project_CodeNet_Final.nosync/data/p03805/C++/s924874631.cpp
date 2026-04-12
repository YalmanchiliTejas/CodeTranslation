#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long int
#define pii pair<int, int>
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m, u, v, z = 0;
    bool b[9][9] = {};
    cin >> n >> m;
    vector<int> a;
    fr(m) cin >> u >> v, b[u][v] = b[v][u] = 1;
    fr1(n) a.push_back(i);
    do {
        bool y = 1;
        for (int i = 1; i < n; i++) if (!b[a[i - 1]][a[i]]) y = 0;
        if (y) z++;
        next_permutation(a.begin(), a.end());
    } while (a[0] == 1);
    cout << z << '\n';
}