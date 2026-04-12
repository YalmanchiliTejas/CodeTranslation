#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {0,0,1,1};
const int dy[] = {0,1,0,1};


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    char z[2] = {'S', 'W'};
    rep(di, 4) {
        string ans(n+2, ' ');
        ans[0] = z[dx[di]];
        ans[1] = z[dy[di]];
        for (int i=2; i<n+2; i++) {
            char c1 = ans[i-1];
            char c2 = s[(i-1)%n];
            if ((c1=='S' && c2=='o') || (c1=='W' && c2=='x')) {
                ans[i] = ans[i-2];
            } 
            else {
                ans[i] = 'S';
                if (ans[i]==ans[i-2]) ans[i] = 'W';
            }
        }
        if (ans[0]==ans[n] && ans[1]==ans[n+1]) {
            ans.pop_back(); ans.pop_back();
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
