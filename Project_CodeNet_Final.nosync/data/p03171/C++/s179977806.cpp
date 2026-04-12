#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


/* range: ± 3.27 * 10^4 */
using i16 = short int;
/* range: 0 to 65535 */
using u16 = short unsigned int;
/* range: ± 2.14 * 10^9 */
using i32 = int;
/* range: 0 to 4.29 * 10^9 */
using u32 = unsigned int;
/* range: ± 9.22 * 10^18 */
using i64 = long long int;
/* range: 0 to 1.84 * 10^19 */
using u64 = long long unsigned int;

array<array<i64, 3000>, 3000> memo;
i64 dp(const vector<i32>& nums, i32 start, i32 end, i32 turn) {
    if (start == end) {
        if (turn == 1) {
            return nums[start];
        }
        return 0;
    }

    if (memo[start][end] != 0) {
        return memo[start][end];
    }

    i64 res = 0;
    if (turn == 1) {
        res = max(nums[start] + dp(nums, start + 1, end, -turn),
                  nums[end] + dp(nums, start, end - 1, -turn));
    } else {
        res = min(dp(nums, start + 1, end, -turn),
                  dp(nums, start, end - 1, -turn));
    }

    memo[start][end] = res;
    return res;
}

i32 main() {
    i32 n = 0;
    cin >> n;

    vector<i32> nums(n);
    for (i32 i = 0; i < n; i++) {
        cin >> nums[i];
    }

    i64 total = accumulate(begin(nums), end(nums), static_cast<i64>(0));
    auto p1_score = dp(nums, 0, n - 1, 1);
    auto p2_score = total - p1_score;
    cout << p1_score - p2_score << '\n';
}