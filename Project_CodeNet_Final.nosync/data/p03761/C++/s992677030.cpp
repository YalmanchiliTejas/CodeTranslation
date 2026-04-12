#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<vector<int>> Alp(n, vector<int>(26, 0));
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, s.size()) {
            Alp[i][(s[j] - 'a')]++; 
        }
    }
    vector<int> ans(26, INF);
    rep(i, 26) {
        rep(j, n) {
            ans[i] = min(ans[i], Alp[j][i]);
        }
    }
    
    rep(i, 26) cout << string(ans[i], 'a' + i);
    cout << endl;

    return 0;
}