#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>
#include <numeric>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;



int main(void)
{
    int n;
    cin >> n;
    int ans = 0;
    int maxh = 0;
    REP(i,n)
    {
        int t;
        cin >> t;
        if(t >= maxh)
        {
            ans++;
        }
        maxh = max(t, maxh);
    }
    cout << ans << endl;
}
