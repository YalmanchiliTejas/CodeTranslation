#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

// https://atcoder.jp/contests/abc058/tasks/arc071_a
void solve() {
    int n;
    cin >> n;
    map<char,int> mp;
    REP(i,n) {
        string s;
        cin >> s;
        if (i==0) {
            REP(j,s.size()) {
                if(mp.count(s[j])==0) mp[s[j]]=0;
                mp[s[j]]++;
            }
        } else {
            map<char,int> smp;
            REP(j,s.size()) {
                if(smp.count(s[j])==0) smp[s[j]]=0;
                smp[s[j]]++;
            }
            // merge
            for(const auto &it: mp) {
                if(smp.count(it.first) == 0) mp[it.first]=0;
                else chmin(mp[it.first],smp[it.first]);
            }
        }

    }
    for(const auto &it:mp) {
        REP(_,it.second) {
            cout << it.first;
        }
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}
