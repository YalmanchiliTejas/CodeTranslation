#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <cctype>    // isupper, islower, isdigit, toupper, tolower
#include <cmath>     // pow
#include <cstdint>   // int64_t, int*_t
#include <cstdio>    // printf
#include <deque>     // deque
#include <iomanip>   // setprecision
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <set>       // set
#include <stack>     // stack
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <utility>       // pair, make_pair
#include <vector>        // vector
using namespace std;

// long long gcd(long long a, long long b) { return b != 0 ? gcd(b, a % b) : a;
// }

// int binary_search(int key) {
//     int ng = -1;
//     int ok = (int)a.size();
//     while(abs(ok - ng) > 1) {
//         int mid = (ok + ng) / 2;
//         if(isOK(mid, key))
//             ok = mid;
//         else
//             ng = mid;
//     }
//     return ok;
// }

// cout << fixed << setprecision(10);
// vector<vector<int>> vec(H, vector<int>(W))    // int H*W
// int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}