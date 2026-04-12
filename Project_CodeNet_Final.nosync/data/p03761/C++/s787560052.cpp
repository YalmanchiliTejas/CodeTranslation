#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(26, 0));
    rep(i, n) {
        string tmp_s;
        cin >> tmp_s;
        rep(j, tmp_s.length()) {
            ++v[i][tmp_s[j]-'a'];
        }
    }
    vector<int> ans(26, 1e8);
    for ( auto tmp_v : v ) {
        rep(i, 26) {
            ans[i] = min(ans[i], tmp_v[i]);
        }
    }
    rep(i, 26) {
        if ( ans[i] == 1e8 ) {
            continue;
        }
        rep(j, ans[i]) {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;
    return 0;
}
