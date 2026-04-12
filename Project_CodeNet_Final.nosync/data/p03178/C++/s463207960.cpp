#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define endl "\n"
#define MOD 1000000007
#define _(a, n) ((((a) % (n)) + (n)) % (n))

ll recurse(ll i, ll rem, bool restrict, const string& num, ll d, vector<vector<vector<ll>>>& dp) {
    ll n = num.length();
    if (dp[i][rem][restrict] != -1) {
        return dp[i][rem][restrict];
    }
    ll count = 0;
    ll up = (restrict ? num[i] - '0' : 9);
    if (i == n-1) {

        for (ll j = 0; j <= up; j++) {
            count += (_(j, d) == rem);
        }
        return dp[i][rem][restrict] = count;
    }

    for (ll j = 0; j <= up; j++) {
        ll newrem = _(rem -j, d);
        count = (count + recurse(i+1, newrem, restrict && j == up, num, d, dp)) % MOD;
    }
    return dp[i][rem][restrict] = count;



}

int main(void) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    string k;
    ll d;
    cin >> k >> d;
    vector<vector<vector<ll>>> dp (k.length(), vector<vector<ll>> (d, vector<ll> (2, -1)));
    cout << _(recurse(0, 0, true, k, d, dp) - 1, MOD) << endl;




    
    return 0;
}