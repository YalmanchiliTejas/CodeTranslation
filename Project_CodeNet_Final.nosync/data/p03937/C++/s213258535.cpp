#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> P;
lli MOD = 1000000007;
int main()
{
    int h, w;
    cin >> w >> h;
    int ans = 0;
    char c;
    rep(i, w * h)
    {
        cin >> c;
        if (c == '#')
            ans++;
    }
    cout << (ans == w + h - 1 ? "Possible" : "Impossible") << endl;
}
