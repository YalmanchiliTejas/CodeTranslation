#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
const ll MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<ll> pref(n + 1, 0);
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + a[i];
        pref[i + 1] %= MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (a[i]*(pref[n] - pref[i + 1]));
        ans %= MOD;
    }
    if(ans < 0){
        ans += MOD;
    }
    cout<<ans;
}