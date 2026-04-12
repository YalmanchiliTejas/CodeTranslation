#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <cctype>    // isupper, islower, isdigit, toupper, tolower
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

int gcd(long long a, long long b) { return b != 0 ? gcd(b, a % b) : a; }
// cout << fixed << setprecision(10);
// vector<vector<int>> vec(H, vector<int>(W))    // int H*W

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long ans;
    if(A + B < 2 * C) {
        ans = A * X + B * Y;
    } else {
        if(X > Y) {
            ans = Y * 2 * C;
            ans += (A < 2 * C) ? A * (X - Y) : C * 2 * (X - Y);
        } else {
            ans = X * 2 * C;
            ans += (B < 2 * C) ? B * (Y - X) : C * 2 * (Y - X);
        }
    }
    cout << ans << endl;
}