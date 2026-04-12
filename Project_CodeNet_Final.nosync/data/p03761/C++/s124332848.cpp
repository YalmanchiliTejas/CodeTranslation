#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;
// int64_t INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s.at(i);
    vvi a(26,vector<ll>(s.size()));
    rep(i,n) sort(s.begin(), s.end());
    rep(i,26){
        char c = 'a'+i;
        rep(j,s.size()){
            rep(k,s.at(j).size()){
                if(s.at(j).at(k)==c) a.at(i).at(j)++;
            }
        }
    }
    // rep(i,a.size()){
    //     rep(j,a.at(i).size()){
    //         cout << "i:" << i << " j:" << j << " a:" << a.at(i).at(j) << endl;;
    //     }
    // }
    string res = "";
    rep(i,26){
        vi b = a.at(i);
        sort(a.at(i).begin(), a.at(i).end());
        rep(j,a.at(i).at(0)){
            res += 'a' + i;
        }
    }
    cout << res << endl;
}