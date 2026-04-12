
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long


int main(){
    string s;
    cin >> s;

    REP(i, s.size() - 1) {
        if(s[i] == 'A' && s[i+1] == 'C') {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;


    return 0;
}
