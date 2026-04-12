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
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(21);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;
int64 mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int64> a(n);
    vector<int64> csum(n);
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }

    int64 ans = 0;

    int64 res=0;
    for(int i=n-1; i>=0; i--) {
        csum[i] = res;
        res += a[i] % mod;
        res %= mod;
    }
    for (int i=0; i<n; i++) {
        ans += a[i] * csum[i] % mod;
    }
    ans %= mod;
    cout << ans << endl;
}