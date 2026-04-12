#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <cctype>    // isupper, islower, isdigit, toupper, tolower
#include <cstdint>   // int64_t, int*_t
#include <cstdio>    // printf
#include <deque>     // deque
#include <iomanip>
#include <iostream> // cout, endl, cin
#include <map>      // map
#include <math.h>
#include <numeric>
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <string>        // string, to_string, stoi
#include <tuple>         // tuple, make_tuple
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <utility>       // pair, make_pair
#include <vector>        // vector
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
const int BG = 1000000007;

int main()
{
    char c;
    cin >> c;

    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
    {
        cout << "vowel" << endl;
    }
    else
    {
        cout << "consonant" << endl;
    }
}
