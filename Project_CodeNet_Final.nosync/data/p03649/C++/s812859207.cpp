#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int cnt = 0, pre = 0, ans = 0;
    bool f = true;
    while(f){
        f = false;
        cnt = 0;
        rep(i, 0, n){
            a[i] += pre;
            if(a[i] >= n){
                f = true;
                int t = a[i] / n;
                a[i] %= n;
                a[i] -= t;
                cnt += t;
            }
        }
        pre = cnt;
        ans += cnt;
    }
    cout << ans << endl;
}