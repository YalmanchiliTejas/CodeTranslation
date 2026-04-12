#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (ll)(v).size()
#define int long long
#define mod 1000000007

void solve() {
        string str; cin >> str;
        bool isA= 0, isB= 0;
        lp(i, 3) {
                if (str[i]== 'A')isA= 1;
                if (str[i]== 'B')isB= 1;
        }
        if (isA&& isB) cout <<"Yes\n";
        else cout << "No\n";
        return;
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int t = 1;
        //cin >> t;
        while ( t-- ) {
                solve();
        }
return 0;
}
