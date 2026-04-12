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
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    rep(i, h) cin >> A[i];
    bool ans = true;
    rep(i, h) {
        rep(j, w) {
            if(i == h - 1 && j == w - 1) continue;
            if(i + 1 >= h || j + 1 >= w) continue;

            if(A[i + 1][j] == '#' && A[i][j + 1] == '#') ans = false;
        }
    }

    if(ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    
    return 0;
}