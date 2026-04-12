#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)

int count(int N)
{
        int ans = 0;
        while (N)
        {
                ans++;
                N /= 10;
        }
        return ans;
}

int main()
{
        int A, B, C, X, Y;
        cin >> A>>B>>C>>X>>Y;
        int ans = min(A * X + B * Y, 2*C * max(X, Y));
        if(X>Y){
                ans = min(ans, 2 * C * Y + A * (X - Y));

        } else{
                ans = min(ans, 2 * C * X + B * (X - Y)*(-1));
        }
        cout << ans << endl;

        return 0;
}
