#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <ctime>
#include <limits>
#include <iomanip>
#include <functional>
#include <array>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;
const ll LL_MAX = 0x7fffffffffffffff;

int main()
{
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;

    char c = s[k - 1];
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
        {
            s[i] = '*';
        }
    }
    cout << s;
    return 0;
}
