#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void solve() {
    int n;
    cin >> n;
    map<char,int> ansmp;
    REP(i,26) ansmp[(char)('a'+i)] = 0;
    REP(i,n) {
        string s;
        cin >> s;
        map<char,int> mp;
        REP(i,26) mp[(char)('a'+i)] = 0;
        for(const auto& it: s) mp[it]++;
        REP(i,26) chmin(ansmp[(char)('a'+i)],mp[(char)('a'+i)]);
        if(i ==0) ansmp = mp;
    }
    string ans;
    REP(i,26) {
        REP(j,ansmp[(char)('a'+i)]) ans.push_back((char)('a'+i));
    }
    cout << ans << endl;

}

int main() {
    solve();
    return 0;
}
