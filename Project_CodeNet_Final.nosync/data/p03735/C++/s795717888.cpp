#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <climits>
#include <unordered_set>
#include <sstream>
#include <stack>

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3;


#define X first
#define Y second
using namespace std;
typedef long long ll;
const ll inf = 1e18;

ll n;
pair<ll,ll> a[200005];

int main()
{
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for(ll i=0;i<n;i++) {
        cin >> a[i].X >> a[i].Y;
        if(a[i].X > a[i].Y) swap(a[i].X, a[i].Y);
    }
    sort(a.begin(), a.end());
    ll XMIN =	inf, XMAX = -inf, YMIN = inf, YMAX = -inf;
    for(ll i=0;i<n;i++) {
        XMIN = min(a[i].X, XMIN);
        XMAX = max(a[i].X, XMAX);
        YMIN = min(a[i].Y, YMIN);
        YMAX = max(a[i].Y, YMAX);
    }
    ll ans = (XMAX - XMIN) * (YMAX - YMIN);

    ll red = YMAX - XMIN;
    ll bu, bl;
    bu = bl = a[0].second;
    for(ll i=1;i<n;i++) {
        ans = min(ans, red * (max(bu, a[n-1].first) - min(bl, a[i].first)));
        bl = min(bl, a[i].second);
        bu = max(bu, a[i].second);
    }
    cout << ans << endl;
}