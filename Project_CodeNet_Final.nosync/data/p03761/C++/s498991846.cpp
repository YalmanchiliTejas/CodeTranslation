#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n;
    cin >> n;
    map<char, int> mp;
    rep(i, 26) {
        mp['a'+i] = mod;
    }
    rep(i, n) {
        string s;
        cin >> s;
        map<char, int> now;
        for (char c: s) {
            now[c]++;
        }
        rep(j, 26) {
            mp['a'+j] = min(mp['a'+j], now['a'+j]);
        }
    }
    rep(i, 26) {
        rep(j, mp['a'+i]) {
            cout << (char)('a'+i);
        }
    }
    cout << endl;
    return 0;
}
