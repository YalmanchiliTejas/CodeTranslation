#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    set<char> ss;
    for (auto &&i : s) {
        ss.insert(i);
    }

    cout << (ss.size() == 2 ? "Yes" : "No") << endl;
}
