#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;
unordered_map<long long, int> exist;

int memo[5050][5050];
vector<int> vs;

int f(int x, int y) {
    if( memo[x][y] != -1 ) return memo[x][y];
    if (exist.count(2 * vs[y] - vs[x]))
        return memo[x][y] = f(y, exist[2 * vs[y] - vs[x]]) + 1;
    return 1;
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        exist[v] = i;
        vs.push_back(v);
    }
    int ans = 0;
    for (int i = 0; i < vs.size(); i++) {
        for (int j = 0; j < vs.size(); j++) {
            if (i != j) ans = max(ans, f(i, j) + 1);
        }
    }
    cout << ans << endl;

}
