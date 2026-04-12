#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    string s;
    cin >> s;

    llint k;
    cin >> k;

    llint n;
    n = s.size();

    vector<vector<llint>> dp0(n+1, vector<llint>(k+2, 0));
    vector<vector<llint>> dp1(n+1, vector<llint>(k+2, 0));

    llint num;
    dp0.at(0).at(0) = 1;
    for(llint in=0;in<n;in++) {
        for(llint ik=0;ik<k+1;ik++) {
            num = s.at(in)-'0';
            if(num>0) {
                dp0.at(in+1).at(ik+1) += dp0.at(in).at(ik);
            }
            else {
                dp0.at(in+1).at(ik) += dp0.at(in).at(ik);
            }
            if(num>0) {
                dp1.at(in+1).at(ik+1) += dp0.at(in).at(ik)*(num-1);
                dp1.at(in+1).at(ik) += dp0.at(in).at(ik);
            }
            dp1.at(in+1).at(ik+1) += dp1.at(in).at(ik)*9;
            dp1.at(in+1).at(ik) += dp1.at(in).at(ik);
        }
    }

    cout << dp0.at(n).at(k)+dp1.at(n).at(k) << endl;
    return 0;
}
