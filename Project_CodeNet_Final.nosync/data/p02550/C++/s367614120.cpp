#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define PB push_back
#define MP make_pair
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define INF (1 << 28)
#define LLINF (1LL << 60)
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
typedef pair<int, int> P;

int main()
{
    ll n,x,m;
    cin>>n>>x>>m;
    ll num[100005] = {};
    ll roopstart = -INF, roopend;
    num[0] = x;
    ll i=1;
    while (1) {
        x = (x * x) % m;
        num[i] = x;
        for(ll j=0;j<i;j++){
            if(num[j]==x){
                roopstart = j;
                roopend = i-1;
            }
        }
        i++;
        if(roopstart!=-INF)
            break;
    }

    ll ans = 0, roopsum = 0;
    for (ll i = 0; i < roopstart; i++) {
        ans += num[i];
    }
    for (ll i = roopstart; i <= roopend;i++){
        roopsum += num[i];
    }
    ans += roopsum * ((n - roopstart) / (roopend - roopstart + 1));
    ll remain = n - (roopstart + (n - roopstart) / (roopend - roopstart + 1) * (roopend - roopstart + 1));
    for (ll i = roopstart; i < roopstart + remain;i++){
        ans += num[i];
    }
    cout << ans << endl;
    return 0;
}
