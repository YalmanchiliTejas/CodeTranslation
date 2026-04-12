#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;

    vector<int> hs(n);
    rep(i, n) { cin >> hs[i]; }

    int maxHeight = -1;
    int ans = 0;

    rep(i, n)
    {
        if (maxHeight <= hs[i]) { ++ans; }
        maxHeight = std::max<int>(maxHeight, hs[i]);
    }

    cout << ans << endl;

    return 0;
}
