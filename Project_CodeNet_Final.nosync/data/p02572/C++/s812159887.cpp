//| #######################|
//|  ADARSH SINGH KUSHWAHA |
//| ###################### |
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Bahut_tej_gand_faad ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frb(i, a, b) for(ll i = a - 1; i >= b; i--)
#define pb push_back
#define ff first
#define ss second
#define mp map<ll,ll>
#define mps map<char,ll>
#define v vector<ll>
#define srt(v) sort(v.begin(),v.end())
#define mod 1000000007
#define max 1000001
void solve() {
    ll n;
    cin >> n;
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        ans += (sum * a);
        ans = ans % mod;
        sum += a;
        sum = sum % mod;
    }
    cout << ans << endl;
}
int main() {
    Bahut_tej_gand_faad;

    //int t;
    //cin >> t;
    //while (t--) {
    solve();
    //}
    return 0;
}