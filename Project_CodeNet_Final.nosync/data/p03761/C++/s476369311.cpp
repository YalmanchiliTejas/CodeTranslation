#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int N; cin >> N;
    map<char, int> res;
    rep(i,N) {
        string S; cin >> S;
        map<char, int> t;
        rep(j,S.size()) t[S[j]]++;
        if (i == 0) {res = t; continue;}
        else for (int a = 'a'; a <= 'z'; a++)
            if (t.count(a)) {if (res.count(a)) chmin(res[a], t[a]);}
            else res.erase(a);
    }

    for (auto x : res) {
        rep(i, x.second) cout << x.first;
    }
    cout << endl;
}
