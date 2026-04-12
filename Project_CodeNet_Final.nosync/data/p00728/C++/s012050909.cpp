#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n, s;
    vector<int> v;

    while (true) {
        cin >> n;

        if (!n) { break; }

        // 全要素を削除
        v.clear();

        for (int i = 0; i < n; i++) {
            cin >> s;
            v.push_back(s);
        }

        int max_v = *max_element(v.begin(), v.end());
        int min_v = *min_element(v.begin(), v.end());
        int sum_v = accumulate(v.begin(), v.end(), 0);

        cout << (sum_v - max_v - min_v) / (n-2) << endl;
    }

    return 0;
}
