#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    rep(i, n) {
        s[i] = (s[i] != s[k - 1]) ? '*' : s[i];
    }
    cout << s << endl;
    return 0;
}
