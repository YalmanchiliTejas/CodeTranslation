#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    string s;
    ll n;
    cin >> n;
    map<char, ll> all;
    vector<map<char, ll> > mp(n);
    rep1(i, n){
        cin >> s;
        rep1(j, s.size()){
            mp[i][s[j]]++;
            all[s[j]]++;
        }
    }
    string ans = "";
    ll add;
    for (auto x: all){
        add = 100;
        rep1(i, n){
            add = min(add, mp[i][x.first]);
        }
        ans += string(add, x.first);
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}