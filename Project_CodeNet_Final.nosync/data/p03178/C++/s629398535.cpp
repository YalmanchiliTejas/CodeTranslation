#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int divVal;
string digit;
//vector<int>v;

ll dp[10009][101][2];

ll recur(int pos, int sum, bool tight) {
    //getchar();
    //for(auto it : v)
    //    cerr << it;
    //cerr << " :: " << pos << ", " << sum << ", " << tight << endl;

    ll &ret = dp[pos][sum][tight];
    if(pos >= digit.size()) {
        /*if(sum == 0) {
            for(auto it : v)
                cerr << it;
            cerr << " :: " << pos << ", " << sum << ", " << tight << endl;
        }*/
        return (sum == 0);
    }

    if(ret != -1)
        return ret;
    ret = 0;

    int lim = tight ? (digit[pos]-'0'):9;
    for(int i = 0; i <= lim; ++i) {
        bool newTight = (i == lim) ? tight:0;
        int newSum = (sum + i)%divVal;
        //v.push_back(i);
        //cerr << "AT POS " << pos << " lim " << lim << " placing " << i << " tight " << tight << endl;
        ret += recur(pos+1, newSum, newTight);
        if(ret >= MOD)
            ret %= MOD;
        //v.pop_back();
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> digit;
    cin >> divVal;
    ll ans = (recur(0, 0, 1) - 1 + MOD)%MOD;
    cout << ans << endl;
    return 0;
}