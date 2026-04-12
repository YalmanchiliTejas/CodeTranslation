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
    long long solve(vector<long long>& S) {
        int n = S.size();
        int N = n - 1;
        long long res = 0;

        for (int i = 1; i < n - 1; ++i) {
            int l = 0;
            int r = n - 1;
            long long sum = 0;
            if ((n - 1) % i == 0) {
                while (l < r) {
                    sum += S[l];
                    sum += S[r];
                    res = max(res, sum);
                    l += i;
                    r -= i;
                }
            } else {
                while (l + i <= n - 1) {
                    sum += S[l];
                    sum += S[r];
                    res = max(res, sum);
                    l += i;
                    r -= i;
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }

    Solution sol;
    cout << sol.solve(S) << "\n";

    return 0;
}