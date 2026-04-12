#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define int ll
signed main(){
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    if(n == 1) {
        if(k == 0) cout << 1 << endl;    
        else cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int b = k+1; b <=n; b++) {
        int q = (n-b+1)/b;
        ans+=(q+1)*((b-1)-k+1);
        if(k == 0) ans--;
        if((q+1)*b+k>n) continue;
        ans += n - (q+1)*b - k + 1;
    }
    cout << ans << endl;
}
