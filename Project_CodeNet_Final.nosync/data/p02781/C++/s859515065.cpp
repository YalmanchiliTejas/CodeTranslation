#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int solve(string s, int k, int i=0, bool flag=false) {
    if(k == 0) return 1;
    int sz = s.size();
    if(i == sz) return 0;
    // もうここからどう選んでもsより小さくなる場合は、flag=true
    // その場合、桁の数字に関係なく好きな数字を選べる
    if(flag) {
        return solve(s, k, i+1, flag) + 9 * solve(s, k-1, i+1, flag);
    }
    // そうでない場合はflag=false
    // この時、その桁の数字を選んだ場合はflag = falseのまま
    else {
        if(s[i] == '0') {
            return solve(s, k, i+1, flag);
        } else {
            return solve(s, k, i+1, true) + (s[i] - '0' - 1) * solve(s, k-1, i+1, true) + solve(s, k-1, i+1, false);
        }
    }

}

int main() {
    string n; cin >> n;
    int k; cin >> k;
    cout << solve(n, k) << endl;
    return 0;
}
