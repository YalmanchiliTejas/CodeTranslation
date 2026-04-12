#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) begin(a),end(a)
template<class T> inline bool chmin(T& a, T b) {return a>b?a=b,true:false;}

signed main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;

    vector<vector<int>> counter(n, vector<int>(26, 0));
    rep(i, n) {
        string s; cin >> s;
        for (auto c : s) {
            counter[i][c-'a']++;
        }
    }
    
    string ans;
    rep(i, 26) {
        int chars = INT_MAX;
        rep(j, n) {
            chmin(chars, counter[j][i]);
        }
        if (chars > 0) {
            string add(chars, 'a'+i);
            ans += add;
        }
    }
        
    cout << ans << endl;
}
