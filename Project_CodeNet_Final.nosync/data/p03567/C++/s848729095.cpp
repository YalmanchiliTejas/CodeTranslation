#include <bits/stdc++.h>

#define NREP() for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define ALL(x) (x).begin(), (x).end()
#define MSG(x) cout << x << endl;
#define IPT(x) ll t; cin >> t; x.push_back(t);
#define YN(x) x ? cout << "YES" << endl : cout << "NO" << endl;
#define Yn(x) x ? cout << "Yes" << endl : cout << "No" << endl;
#define yn(x) x ? cout << "yes" << endl : cout << "no" << endl;

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<string> vvs;

const static ll MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    REP(i, s.length() - 1) {
        if (s.at(i) == 'A' && s.at(i + 1) == 'C') {
            MSG("Yes")
            exit(0);
        }
    }

    MSG("No")
}
