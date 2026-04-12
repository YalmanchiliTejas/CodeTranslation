// Contest No.: ABC177
// Problem No.: C
// Solver:      Jinmin Goh
// Date:        20200829

#include <cstring>
#include <iostream>
#include <cstdlib>
#include <list>
#include <array>
#include <atomic>
#include <algorithm>
#include <deque>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long int nums[200010];

int main() {
    long long int n, modVal = 1e9 + 7;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }

    long long allSum = 0, squareSum = 0;
    for(int i = 0; i < n; i++) {
        allSum += nums[i];
        allSum %= modVal;
        squareSum += (nums[i] * nums[i]);
        squareSum %= modVal;
    }
    long long squareVal = (allSum * allSum) % modVal;

    long long ans = squareVal - squareSum;
    
    if(ans < 0) {
        ans += modVal;
    }

    if(ans % 2) {
        ans += modVal;
    }
    ans /= 2;
    printf("%lld", ans);
    return 0;
}