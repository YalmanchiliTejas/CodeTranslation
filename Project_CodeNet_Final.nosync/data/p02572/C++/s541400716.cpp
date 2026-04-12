#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector a(n,0);
    for (int i=0; i<n; i++) cin >> a[i];

    int64 ans = 0;
    int64 csum = 0;
    for (int i=0; i<n; i++) {
        ans += csum * a[i];
        csum += a[i];
        ans %= MOD;
        csum %= MOD;
    }

    cout << ans << endl;
}