#include <bits/stdc++.h>
using namespace std;
#define __ <<" "<<
#define ___ <<" "
#define bash push_back
#define ALL(x) x.begin(),x.end()
// #define int long long
struct IoSetup {
    IoSetup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
}IoSetup;

using Int = __int128_t;
using ll = long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int SMOD = 1000000007;
constexpr int NMOD = 998244353;
constexpr int dx[]={1,0,-1,0,1,1,-1,-1};
constexpr int dy[]={0,-1,0,1,-1,1,-1,1};

inline bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T&b){if(a<b)return(a=b,1);return 0;}
template<class T>bool chmin(T &a, const T&b){if(b<a)return(a=b,1);return 0;}


signed main() {

    int n;
    cin >> n;
    vector<int> a(n);

    ll sum = 0;
    ll ans = 1;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] * sum % SMOD;
        ans %= SMOD;
        sum += a[i];
        sum %= SMOD;
    }

    cout << ans - 1<< endl;

    return 0;
}