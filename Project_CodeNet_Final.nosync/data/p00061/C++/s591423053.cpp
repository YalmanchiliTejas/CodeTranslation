#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;

struct GreaterPII {
    bool operator() (const PII & a, const PII & b) const {
        return a.second > b.second;
    }
};


int main() {
    int n, s;
    char d;
    vector<PII> p_map;
    while (cin >> n >> d >> s) {
        if (n == 0 && s == 0) break;
        p_map.push_back(PII(n, s));
    }
    stable_sort(p_map.begin(), p_map.end(), GreaterPII());
    int q; int prev;
    int rank[p_map.size()];
    for (int i = 0; i < p_map.size(); i++) {
        rank[p_map[i].first] = rank[p_map[i-1].first]+1;
        if (prev == p_map[i].second) {
            rank[p_map[i].first] = rank[p_map[i-1].first];
        }
        prev = p_map[i].second;
    }
    while (cin >> q) {
        cout << rank[q] << endl;
    }
    return 0;
}
        