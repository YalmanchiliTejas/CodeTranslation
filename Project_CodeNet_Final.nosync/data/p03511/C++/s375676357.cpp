#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

ll ls;
string s, t;

int main(){
    cin >> ls >> s >> t;
    ll sm = 0, tm = 0;
    ll ss = s.size(), ts = t.size();
    for (ll i = 0; i <= ls; i++) {
        if (ss * i > ls) break;
        if ((ls - ss*i)%ts == 0) {
            sm = max(sm, i);
            tm = max(tm, (ls-ss*i)/ts);
        }
    }
    string out1;
    rep(i,sm) out1 += s;
    rep(i,(ls-ss*sm)/ts) out1 += t;
    string out2;
    rep(i,tm) out2 += t;
    rep(i,(ls-ts*tm)/ss) out2 += s;
    cout << min(out1, out2) << endl;
}






























