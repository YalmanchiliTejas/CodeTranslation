#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    sort(a.begin(), a.end());
    int ma = 0;
    vector<vector<bool>> used(n, vector<bool>(n));
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        if (used[i][j]) continue;
        used[i][j] = true;
        int diff = a[j] - a[i];
        int tmp = 2, pre = j;
        for (int k = a[j] + diff; k <= a.back(); k += diff) {
            int itr = lower_bound(begin(a), end(a), k) - begin(a);
            if (a[itr] != k) break;
            tmp++;
            used[pre][itr] = true;
            pre = itr;
        }
        ma = max(ma, tmp);
    }
    cout << ma << endl;
    return 0;
}
