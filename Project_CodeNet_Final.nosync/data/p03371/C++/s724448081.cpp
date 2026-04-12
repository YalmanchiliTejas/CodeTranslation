#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA() cerr << "AAAAA" << endl
#define debug_() cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = a * x + b * y;
    while (true)
    {
        if (ans - a - b + 2 * c < ans && x - 1 >= 0 && y - 1 >= 0)
        {
            x--;
            y--;
            ans = ans - a - b + 2 * c;
        }
        else if (ans - b + 2 * c < ans && x == 0 && y - 1 >= 0)
        {
            y--;
            ans = ans - b + 2 * c;
        }
        else if (ans - a + 2 * c < ans && x - 1 >= 0 && y == 0)
        {
            x--;
            ans = ans - a + 2 * c;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
