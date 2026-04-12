#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    rep(i, H) cin >> A[i];

    int y = 0, x = 0;
    bool ans = true;
    rep(i, H)rep(j, W) {
        if (A[i][j] == '#') {
            if (i < y || j < x) {
                ans = false;
                break;
            }
            y = i, x = j;
        }
    }

    cout << (ans ? "Possible" : "Impossible") << endl;
}