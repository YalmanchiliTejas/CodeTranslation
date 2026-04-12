#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <cstring>
#include <cmath>
#include <tuple>
#include <complex>
#include <bitset>
#include <climits>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using pii = pair<int, int>;
using pll = pair<LL, LL>;
using pld = pair<LD, LD>;
const int M = 1e9 + 7;


inline int my_mod(const LL a, const int m = M)
{
    return (a % m + m) % m;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> nrs(N);
    LL mod_sum = 0;
    for (int &nr : nrs)
    {
        cin >> nr;

        mod_sum = my_mod(mod_sum + nr);
    }
    // mod_sum = my_mod(mod_sum - nrs.front());
    // cerr << "mod sum: " << mod_sum << "\n";

    LL res = 0;
    for (int i = 0; i < N; ++i)
    {
        mod_sum = my_mod(mod_sum - nrs[i]);

        res = my_mod(res + my_mod(nrs[i] * mod_sum));
    }

    cout << res;
}
