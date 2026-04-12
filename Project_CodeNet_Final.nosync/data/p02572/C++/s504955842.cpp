#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)
#define ull unsigned long long int
#define ll long long int
#define m_p(x,y) make_pair(x,y)

void showVec(vector<ll> &v) {
    for(auto it:v) {
        cout << it << endl;
    }
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main() {
    fastIO();
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> pref(n);
    cin >> v[0];
    pref[0] = v[0];
    for(int i=1;i<n;i++) {
        cin >> v[i];
        pref[i] = v[i] + pref[i-1];
        pref[i] %= mod;
    }
    ll res = 0;
    for(int i=1;i<n;i++) {
        res += pref[i-1] * v[i];
        res %= mod;
    }
    cout << res << "\n";




    return 0;
}