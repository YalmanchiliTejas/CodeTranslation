#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, 0, n) cin >> d[i];
    bool f = true;
    int now = 0;
    rep(i, 0, n - 1){
        if(now >= i){
            now = max(now, i + d[i] / 10);
        }
    }
    if(now < n - 1) f = false;
    now = n - 1;
    repb(i, n - 1, 1){
        if(now <= i){
            now = min(now, i - d[i] / 10);
        }
    }
    if(now > 0) f = false;
    cout << (f ? "yes" : "no") << endl;
}