#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#include <map>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
typedef long long ll;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
    string s;
    cin >> s;
    string ans = "No";
    FOR(i, 1, 3) {
        if(s[i-1] != s[i]){
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
}

