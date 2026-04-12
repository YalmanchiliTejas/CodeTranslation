#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;

#define rep(i, n) REP(i, 0, (n))
#define REP(i, a, n) for(int i=(a); i<(n); i++)
#define pb push_back

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    
    char c = s[k-1];
    string ans = "";
    rep(i, s.size()) ans += (s[i]==c)? c:'*';
    
    cout << ans << endl;
}