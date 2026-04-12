#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,a,n) for(ll i=(a); i<(ll)(n); i++)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(v) (v).begin(), (v).end()

int main(void) {
    string s;
    cin >> s;
    for (int i=0; i<s.size()-1; i++) {
        if (s[i] == 'A' && s[i+1] == 'C') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
