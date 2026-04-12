#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define int long long
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, 0, n){
        cin >> h[i];
    } 
    int ans = 1;
    rep(i, 1, n){
        bool f = true;
        rep(j, 0, i){
            if(h[j] > h[i]) f = false;
        }
        if(f) ans++;
    }
    cout << ans << endl;
}