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
    string s;
    string t = "yuiophjklnm";
    while(1){
        cin >> s;
        if(s == "#") break;
        int ans = -1;
        int pre = -1;
        rep(i, 0, s.size()){
            int now = 0;
            if(t.find(s[i]) != string::npos) now = 1;
            if(pre != now){
                ans++;
            }
            pre = now;
        }
        cout << ans << endl;
    }
}
