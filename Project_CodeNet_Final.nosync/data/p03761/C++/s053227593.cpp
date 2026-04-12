#include <iostream> // cout, endl, cin
#include <iomanip>
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
#include <math.h>
#include <numeric>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
const int BG = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<string> S(n);
    rep(i, n) cin >> S[i];

    string ans = S[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int flag = 1;
            for (int l = 0; l < S[i].size(); l++)
            {
                if (ans[j] == S[i][l])
                {
                    S[i][l] = '0';
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                ans[j] = '1';
            }
        }
    }
    string a;
    for (char i : ans)
    {
        if (i != '1')
        {
            a.push_back(i);
        }
    }
    sort(a.begin(), a.end());
    cout << a << endl;
}
