// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

ll swdp[101][10][2][4]; // swdp[cdig][digit val][eq to q][nonzero]

#define SWDP_COND(prevdig, nexdig) if(max(prevdig-nexdig, nexdig-prevdig) >= 2)

// assuming there are no preceding zeroes

int K;

ll _solve_swdp(string s) {
    memset(swdp, 0, sizeof swdp);
    swdp[0][s[0]-'0'][1][s[0] != '0'] = 1;
    // change to 0 if can have preceding zeroes
    iter(d, 0, s[0]-'0') swdp[0][d][0][d != 0] = 1;
    rep1(dig, s.size()-1) {
        rep(pdval, 10) rep(dval, 10)
            rep(d, 4) if(d || !dval) swdp[dig][dval][0][d] += swdp[dig-1][pdval][0][d - (dval != 0)];
        rep(dval, s[dig]-'0')
            rep(d, 4) if(d || !dval) swdp[dig][dval][0][d] += swdp[dig-1][s[dig-1]-'0'][1][d - (dval != 0)];
        rep(d, 4) if(d || s[dig] == '0') swdp[dig][s[dig]-'0'][1][d] += swdp[dig-1][s[dig-1]-'0'][1][d - (s[dig] != '0')];
    }
    ll ans = 0; rep(dval, 10) ans += swdp[s.size()-1][dval][0][K] + swdp[s.size()-1][dval][1][K];
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s >> K;
    cout << _solve_swdp(s) << endl;
}

