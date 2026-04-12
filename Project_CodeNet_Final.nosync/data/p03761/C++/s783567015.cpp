#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < n; i++)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    vector<string> S(N);
    rep (i, N) {
        cin >> S[i];
    }

    vector<ll> count(26, INF);
    rep (i, N) {
        vector<ll> tmp(26, 0);
        rep (j, S[i].size()) {
            tmp[S[i][j] - 'a']++;
        }
        rep (j, 26) {
            count[j] = min(count[j], tmp[j]);
        }
    }

    string ans = "";
    rep (i, 26) {
        rep (j, count[i]) {
            ans += i+'a';
        }
    }

    cout << ans << endl;
    return 0;
}