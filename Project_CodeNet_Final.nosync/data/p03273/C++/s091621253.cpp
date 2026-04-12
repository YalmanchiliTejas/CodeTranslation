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
    int H, W;
    cin >> H >> W;
    vector<vector<string>> A(H, vector<string>(W));
    rep(i, H) {
        string s;
        cin >> s;
        rep(j, W) {
            A[i][j] = s[j];
        }
    }
    vector<bool> h(H, false), w(W, false);
    rep(i, H) {
        rep(j, W) {
            if(A[i][j] == "#") {
                h[i] = true;
                break;
            }
        }
    }
    rep(i, W) {
        rep(j, H) {
            if(A[j][i] == "#") {
                w[i] = true;
                break;
            }
        }
    }
    rep(i, H) {
        if(h[i] == false) continue;
        rep(j, W) {
            if(w[j] == false) continue;
            cout << A[i][j];
        }
        cout << endl;
    }

    return 0;
}