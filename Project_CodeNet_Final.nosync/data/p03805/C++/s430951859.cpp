// common include
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main() {
    int n, m;
    int i, j, k;
    vector<P> v;
    vector<int> num;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> j >> k;
        v.push_back(P(j, k));
    }
    for (i = 1; i <= n; i++) {
        num.push_back(i);
    }
    int result = 0;
    do {
        if (num[0] != 1) break;
        bool complete = true;
        for (i = 0; i < n - 1; i++) {
            bool exist = false;
            for (j = 0; j < v.size(); j++) {
                if (num[i] == v[j].first && num[i + 1] == v[j].second || num[i + 1] == v[j].first && num[i] == v[j].second) {
                    exist = true;
                    break;
                }
            }
            if (!exist) complete = false;
        }
        if (complete) result++;
    } while (next_permutation(num.begin(), num.end()));
    cout << result << endl;
    return 0;
}
