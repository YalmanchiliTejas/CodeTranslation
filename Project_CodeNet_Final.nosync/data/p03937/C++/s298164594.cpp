#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <list>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(s,i,n) for(int i=s;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define skip(i,n,p) for(int i=0;i<n;i+=p)
#define int64 long long
#define debug cout << __FILE__ << ":" << __LINE__ << endl;

struct Init {
    Init() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.precision(20);
        cout << fixed;
    }
} init;

template <typename _Ty>
ostream& operator << (ostream& ostr, const vector<_Ty>& v) {
    for(int i = 0; i < (int) v.size(); i++) {
        ostr << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return ostr;
}

int gcd(int a, int b) {
    if (a < b) a, b = b, a;
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int N, W;
vector<string> M(8);

void dfs(int i, int j) {
    if (i + 1 < N && M[i+1][j] == '#') {
        M[i+1][j] = '.';
        dfs(i+1, j);
    } else if (j + 1 < W && M[i][j+1] == '#') {
        M[i][j+1] = '.';
        dfs(i, j+1);
    }
}

int main() {
    cin >> N >> W;
    rep(i, N) cin >> M[i];
    M[0][0] = '.';
    dfs(0, 0);
    rep(i, N) {
        rep(j, W) {
            if (M[i][j] == '#') {
                cout << "Impossible" << endl;
                exit(0);
            }
        }
    }
    cout << "Possible" << endl;
}
