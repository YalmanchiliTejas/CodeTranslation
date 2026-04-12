#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define Rep(i, n) for( int i = 0; i < (n); i++ )
#define Rrep(i, a, n) for( int i = (a); i < (n); i++ )
#define All(v) v.begin(), v.end()

typedef pair<int, int> Pii;
typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;

signed main() {
    string s;
    cin >> s;
    bool flag = false;
    Rep(i, (int)s.size()-1) {
        if ( s[i] == 'A' && s[i+1] == 'C' ) flag = true;
    }

    if ( flag ) cout << "Yes" << endl;
    else cout << "No" << endl;
}
