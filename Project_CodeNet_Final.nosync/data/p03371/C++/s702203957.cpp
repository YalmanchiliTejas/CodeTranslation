#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 0;

    if(a+b < 2*c) ans += (a+b) * (min(x,y));
    else ans += 2*c*(min(x,y));

    if(x > y){
        if(a < 2*c) ans += a*(x-y);
        else ans += 2*c*(x-y);
    }
    if(x < y){
        if(b < 2*c) ans += b*(y-x);
        else ans += 2*c*(y-x);
    }

    cout << ans << endl;
    return 0;
}
