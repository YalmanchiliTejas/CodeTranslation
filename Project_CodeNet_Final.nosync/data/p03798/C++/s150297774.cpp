#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    bool flag = false;
    vector<char> ans;

    for (int bit = 0; bit < 4 ; bit ++) {
        ans = {};
        int ani0 = (bit>>0)&1;
        int ani1 = (bit>>1)&1;

        if (ani0) ans.push_back('W');
        else ans.push_back('S');
        if (ani1) ans.push_back('W');
        else ans.push_back('S');
        
        int before1 = ani1;
        int before2 = ani0;
        for (int i = 0; i < n - 1 ; i ++ ) {
            int tmp;
            if (s.at(i + 1) == 'o') tmp = before1^before2;
            else tmp = before1^before2^1;

            before2 = before1;
            before1 = tmp;

            if (i != n - 2) {
                if (before1) ans.push_back('W');
                else ans.push_back('S');
            }
        }
        
        int tmp;
        if (s.at(0) == 'o') tmp = before1^before2;
        else tmp = before1^before2^1;

        before2 = before1;
        before1 = tmp;

        if (before1 == ani1 && before2 == ani0) {
            flag = true;
            break;
        }
    }

    if (flag) {
        for (int i = 0; i < n; i ++) cout << ans[i];
        cout << '\n';
    }
    else cout << -1 << endl;
}

