#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0;

    int cur_max = INT_MIN;
    while (n--) {
        int k; cin >> k;
        if (k >= cur_max) res++;
        cur_max = max(cur_max, k);
    }

    cout << res << endl;

    return 0;
}