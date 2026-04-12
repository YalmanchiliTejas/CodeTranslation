#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "functional"
#include "cmath"
#include "set"

using namespace std;

struct path {
    int end_pos;
    set<int> passed_nodes;
};

int dps_path_number(const path& current_path, const vector<vector<bool>>& edges, const int node_number) {
    if((int)current_path.passed_nodes.size() == node_number) {
        return 1;
    }

    int sum_path_number = 0;

    for (int i = 0; i < node_number; i++) {
        if (edges[current_path.end_pos][i] == true && current_path.passed_nodes.count(i) == 0) {
            set<int> next_passed_nodes = current_path.passed_nodes;
            next_passed_nodes.insert(i);
            path next_path{i, next_passed_nodes};

            sum_path_number += dps_path_number(next_path, edges, node_number);
        }

    }
    return sum_path_number;
}

int main() {
    // get values from input
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> edges(N, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        ai--;
        bi--;

        edges[ai][bi] = true;
        edges[bi][ai] = true;
    }
    // main procedure
    path first_path{0, set<int>{0}};
    int answer = dps_path_number(first_path, edges, N);

    // output
    cout << answer << endl;
    return 0;
}
