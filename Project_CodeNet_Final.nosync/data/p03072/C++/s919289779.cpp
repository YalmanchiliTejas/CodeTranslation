#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <tuple>
#include <cstring>
#include <cctype>
#include <ctype.h>
#include <ios>
#include <iomanip>

#define INF 200000000
#define MOD 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    int ans = 0;
    int maxh = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];

        if (maxh <= h[i])
        {
            maxh = max(h[i], maxh);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
