#include <bits/stdc++.h>

#define NREP() for(ll i = 0; i < n; i++)
#define MREP() for(ll j = 0; j < m; j++)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define ALL(x) (x).begin(), (x).end()
#define MSG(x) cout << x << endl;
#define IPT(t, x) t ipt; cin >> ipt; x.push_back(ipt);
#define YN(x) x ? cout << "YES" << endl : cout << "NO" << endl;
#define Yn(x) x ? cout << "Yes" << endl : cout << "No" << endl;
#define yn(x) x ? cout << "yes" << endl : cout << "no" << endl;

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;

const static ll MOD = 1e9 + 7;
ll n, cnt, ans, tmp, sum, a, b, c, d, k, m, h, w, q, x, y;
string s, t;

int main() {
    ll z;
    cin >> x >> y >> z;
    ll sum = z;
    ans = 0;
    while (sum < x) {
        sum += y + z;
        ans++;
    }
    if (sum > x) ans--;
    MSG(ans)
}
