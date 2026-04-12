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
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 1e9;
    for(int i = 0;i <= max(x,y)*2;i+=2)
    {
        int rx,ry;
        rx = max(x - i/2, 0);
        ry = max(y - i/2, 0);
        ans = min(ans, i*c+rx*a+ry*b);
    }
    cout << ans << endl;
}
