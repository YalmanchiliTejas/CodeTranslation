#include <bits/stdc++.h>

#define NREP() for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define ALL(x) (x).begin(),(x).end()
#define MSG(x) cout << x << endl;
#define YN(x) x ? cout << "YES" << endl : cout << "NO" << endl;
#define Yn(x) x ? cout << "Yes" << endl : cout << "No" << endl;
#define yn(x) x ? cout << "yes" << endl : cout << "no" << endl;

using namespace std;
using ll = long long;
const static ll MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    vector<string> v(n);
    NREP() {
        string tmp;
        cin >> tmp;
        sort(ALL(tmp));
        v[i] = tmp;
    }

    string ans = "";
    for (char c = 'a'; c <= 'z'; ++c) {
        ll cnt = LONG_LONG_MAX;
        NREP() {
            ll tmp = count(ALL(v[i]), c);
            cnt = min(tmp, cnt);
        }

        REP(i, cnt) {
            ans += c;
        }
    }

    MSG(ans)
    return 0;
}
