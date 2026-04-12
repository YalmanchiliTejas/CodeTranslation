#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
const ll inf = 1e9;
int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    int q; cin >> q;
    rep(i,q){
        ll k;
        cin >> k;
        vector<ll>::iterator it = lower_bound(all(a), k);
        int ans = it - a.begin();
        cout << ans << endl;
    }
    return 0;
}
