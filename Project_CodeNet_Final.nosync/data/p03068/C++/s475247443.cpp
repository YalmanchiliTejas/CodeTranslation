#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    k--;
    char c = s[k];
    rep(i,n) {
        if (s[i] != c) s[i] = '*';
    }
    cout << s << endl;
}