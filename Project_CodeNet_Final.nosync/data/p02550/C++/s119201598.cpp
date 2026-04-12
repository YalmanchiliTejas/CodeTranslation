#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <map>
#include <time.h>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

map<int, P> mp;

signed main() {
    int n, x, m, ans = 0, ki = 0;
    cin >> n >> x >> m;

    while(1) {
        ki++;
        if(mp[x].second) {
            P p = mp[x];
            int plus = ans - p.first;
            int hab = ki - p.second;

            ans += ((n - ki) / hab) * plus;
            ki += hab * ((n - ki) / hab);
        }
        mp[x] = P(ans, ki);
        ans += x;
        x *= x;
        x = x % m;
        if(ki == n) break;
    }

    cout << ans << endl;
}
