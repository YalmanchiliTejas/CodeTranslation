#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0;i < n;i++){
        cin >> s[i];
    }

    vector<vector<ll>> x(n, vector<ll>(26));
    for (ll i = 0; i < n; i++){
        ll m = s[i].size();
        for (ll j = 0; j < m; j++){
            x[i][s[i][j] - 'a']++;
        }
    }

    for (ll i = 0; i < 26; i++){
        ll c = x[0][i];
        for (ll j = 0; j < n; j++){
            c = min(c,x[j][i]);
        }
        char w = 'a' + i;
        for (ll k = 0; k < c; k++){
            cout << w;
        }
    }
    cout << endl;
}