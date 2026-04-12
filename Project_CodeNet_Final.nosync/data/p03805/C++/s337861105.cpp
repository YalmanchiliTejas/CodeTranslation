#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)

using Node = vector<int>; // 隣接リスト
using NodeList = vector<Node>;

int main() {
    int n, m;
    cin >> n >> m;
    NodeList nodes(n, Node(vector<int>(0)));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    int ans = 0;
    function<void(int, vector<int>)> dfs = [&ans, &nodes, &n, &dfs](int index, vector<int> visited) {
        visited.push_back(index);
        auto children = nodes[index];
        auto result = remove_if(children.begin(), children.end(), [&visited](auto x) {
            return std::find(visited.begin(), visited.end(), x) != visited.end();
        });
        children.erase(result, children.end());
        if (children.size() == 0) {
            if (visited.size() == n) ans++;
        } else {
            for (auto nextNode : children) {
                dfs(nextNode, visited);
            }
        }
    };

    dfs(0, vector<int>(0));
    cout << ans << endl;
}
