#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

const bool debug = false;

int main() {
    int n, m;
    cin >> n >> m;
    auto adj = new vector<int>[n];
    for (size_t i = 0; i < n; ++i) {
        adj[i] = vector<int>();
    }
    for (size_t i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    {
        int ones = 0;
        for (size_t i = 0; i < n; ++i) {
            if (adj[i].size() == 0) {
                cout << 0 << endl;
                return 0;
            }
            if (adj[i].size() == 1 && i != 0) {
                ++ones;
            }
        }
        if (ones > 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    int paths = 0;
    queue< tuple< int, int, vector<bool> > > q;
    vector<bool> initial;
    for (size_t i = 0; i < n; ++i) {
        initial.push_back(false);
    }
    initial[0] = true;
    q.push(make_tuple(1, 0, initial));
    while(!q.empty())
    {
        tuple< int, int, vector<bool> > f = q.front();
        if (debug) {
            cout << "Q " << get<0>(f) << ' ' << get<1>(f) << " [";
            for (size_t i = 0; i < n; ++i) {
                cout << get<2>(f)[i] << ',';
            }
            cout << "]\n";
        }

        int num_visit = get<0>(f);
        if (num_visit == n) {
            ++paths;
            q.pop();
        } else {
            int current_pos = get<1>(f);
            vector<bool> visited = get<2>(f);
            for (size_t i = 0; i < adj[current_pos].size(); ++i) {
                int next_pos = adj[current_pos][i];
                if (!visited[next_pos]) {
                    vector<bool> next_visited(visited);
                    next_visited[next_pos] = true;
                    q.push(make_tuple(num_visit+1, next_pos, next_visited));
        if (debug) {
            cout << "A " << num_visit+1 << ' ' << next_pos << " [";
            for (size_t i = 0; i < n; ++i) {
                cout << next_visited[i] << ',';
            }
            cout << "]\n";
        }
                }
            }
            q.pop();
        }
    }
    cout << paths << endl;
    return 0;
}
