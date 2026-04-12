#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H, string(W, ' '));
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    }

    set<int> row, col;
    for (int i = 0; i < H; i++) {
        row.insert(i);
    }
    for (int j = 0; j < W; j++) {
        col.insert(j);
    }
    for (int i = 0; i < H; i++) {
        bool remove = true;
        for (int j = 0; j < W; j++) {
            if (a[i][j] != '.') {
                remove = false;
                break;
            }
        }
        if (remove) {
            row.erase(i);
        }
    }
    for (int j = 0; j < W; j++) {
        bool remove = true;
        for (int i = 0; i < H; i++) {
            if (a[i][j] != '.') {
                remove = false;
                break;
            }
        }
        if (remove) {
            col.erase(j);
        }
    }

    for (auto& i : row) {
        for (auto& j : col) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
