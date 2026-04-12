#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<pair<int, short> > que;
    short full = 0;
    for (int i = 0; i < n; i++) {
        full <<= 1;
        full |= 1;
    }
    unordered_map<int, vector<int> > mp;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        mp[a].push_back(b);
        mp[b].push_back(a);
        if (a == 0) {
            que.push(pair<int, short>(b, 1));
        }
    }

    int count = 0;
    while (!que.empty()) {
        pair<int, short> p = que.front();
        que.pop();
        short now = p.second;
        short next = (1 << p.first) | now;
        if (next == full) {
            count++;
        } else if (next != now) {
            for (int x: mp[p.first]) {
                que.push(pair<int, short>(x, next));
            }
        }
    }
    cout << count << endl;
    return 0;
}
