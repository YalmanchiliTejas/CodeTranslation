#include <bits/stdc++.h>
using namespace std;

vector<int> v[100010];
bool win = false;

int search(int curr, int prev) {
    if (win) return -1;
    int c = 0;
    for (auto &next: v[curr]) {
        if (next == prev) continue;
        c += search(next, curr);
    }
    if (c >= 2) win = true;
    return (c + 1) % 2;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    if (search(0, -1) == 1) win = true;
    if (win) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}