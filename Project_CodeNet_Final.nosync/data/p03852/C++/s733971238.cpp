/*
ID: y1197771
PROG: test
LANG: C++
*/
#include<bits/stdc++.h>
#define pb push_back
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define dbg(x) cout << #x << " at line " << __LINE__ << " is: " << x << endl
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e3 + 10;
void solve() {
    char a;
    cin >> a;
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
        cout << "vowel" << endl;
    } else cout << "consonant" << endl;
}
int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
