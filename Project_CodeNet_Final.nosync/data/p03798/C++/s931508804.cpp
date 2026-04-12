#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

bool check(string s, vector<int>& a, int k) {
    if (a[0]==0) {
        if (s[0]=='o' && a[k]!=a[1]) return false;
        if (s[0]=='x' && a[k]==a[1]) return false;
    } else {
        if (s[0]=='x' && a[k]!=a[1]) return false;
        if (s[0]=='o' && a[k]==a[1]) return false;
    }
    return true;
}

void answer(vector<int>& a) {
    for(const auto& aa: a) cout << ((aa==0)?'S':'W');
    cout << endl;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    const int ini[] = {0, 1}; // 羊:0, 狼:1
    rep(i, 2) rep(j, 2) {
        rep(k, n) a[k]=-1;
        a[0] = ini[i]; a[1] = ini[j];
        FOR(k, 1, n) {
            if (k<n-1) {
                if (a[k]==0) {
                    if (s[k]=='o') a[k+1] = a[k-1];
                    else a[k+1] = 1-a[k-1];
                } else {
                    if (s[k]=='x') a[k+1] = a[k-1];
                    else a[k+1] = 1-a[k-1];
                }
            } else {
                debug(a);
                if (a[k]==0) {
                    if (s[k]=='o') {
                        if (a[k-1]==a[0]) {
                            if (!check(s, a, k)) continue;
                            answer(a);
                            return 0;
                        }
                    } else {
                        if (a[k-1]!=a[0]) {
                            if (!check(s, a, k)) continue;
                            answer(a);
                            return 0;
                        }
                    }
                } else {
                    if (s[k]=='x') {
                        if (a[k-1]==a[0]) {
                            if (!check(s, a, k)) continue;
                            answer(a);
                            return 0;
                        }
                    } else {
                        if (a[k-1]!=a[0]) {
                            if (!check(s, a, k)) continue;
                            answer(a);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}