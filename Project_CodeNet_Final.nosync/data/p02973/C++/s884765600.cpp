#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;

class Solution {
public:
    int solve(vector<int>& A) {
        int n = A.size();

        multiset<int> M;

        for (auto x : A) {
            if (M.empty()) {
                M.insert(x);
            } else {
                auto it = M.lower_bound(x);
                if (it == M.begin()) {
                    M.insert(x);
                } else {
                    --it;
                    M.erase(it);
                    M.insert(x);
                }
            }
        }

        return M.size();
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    Solution sol;
    cout << sol.solve(A) << "\n";

    return 0;
}