#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) x.begin(),x.end()
#define ln '\n'
const long long MOD = 1000000007LL;
//const long long MOD = 998244353LL;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string S; cin >> S;
    bool ok = false;
    if (S[0]==S[1]&&S[1]==S[2]) ok = true;
    cout << (ok ? "No" : "Yes") << ln;
}