#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

int main() {
    ll n;
    cin >> n;
    vl vec(n);
    ll sum = 0;
    rep(i, n){
        ll num;
        cin >> num;
        vec[i] = num;
        sum += num;
        sum %= mod;
    } 
    ll ans = 0;
    ll no = 0;
    rep(i, n){
        no += vec[i];
        no %= mod;
        ll gap = sum - no;
        if(gap < 0) gap += mod;
        ll tmp = vec[i]*gap;
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}