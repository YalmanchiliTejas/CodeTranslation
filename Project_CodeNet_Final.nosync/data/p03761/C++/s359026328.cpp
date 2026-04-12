/**
*    created: 09.07.2020 00:52:04
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    rep(i,n) cin >> v[i];
    string m = v[0];
    rep(i,n) if (v[i].size() < m.size()) m = v[i];
    map<char,int> mp;
    rep(i,m.size()) mp[m[i]]++;
    for (auto p : mp) {
        bool ok = true;
        int num = p.second;
        rep(i,n) {
            string t = v[i];
            int cnt = 0;
            rep(j,t.size()) if (t[j] == p.first) cnt++;
            if (cnt == 0) ok = false;
            else  chmin(num,cnt);
        }
        if (!ok) continue;
        else rep(i,num) cout << p.first; 
    }
    cout << endl;
    return 0;
}