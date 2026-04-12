#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

void dfs(int cur, vector<vector<int>> &tree, vector<bool> check, int &ans) {
    check.at(cur) = true;
    bool flag = true;
    for (int a : tree.at(cur)) {
        if (!check.at(a)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        flag = true;
        for (bool a : check) {
            if (!a) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
            return;
        }
    }
    for (int a : tree.at(cur)) {
        if (!check.at(a)) {
            dfs(a, tree, check, ans);
        }
    }
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<pair<int, int>> pass(m);
    for (int i=0; i<m; i++) {
        cin >> pass.at(i).first >> pass.at(i).second;
    }
    vector<vector<int>> tree(n);
    for (int i=0; i<m; i++) {
        tree.at(pass.at(i).first-1).push_back(pass.at(i).second-1);
        tree.at(pass.at(i).second-1).push_back(pass.at(i).first-1);
    }
    vector<bool> check(n, false);
    int ans = 0;
    dfs(0, tree, check, ans);
    cout << ans << endl;
    return 0;
}
