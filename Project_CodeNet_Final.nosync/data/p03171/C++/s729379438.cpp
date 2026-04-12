#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

int N, A[3003];
ll M[3003][3003];

ll f(int l, int r) {
    ll &re = M[l][r];
    if (re > -1)RT re;
    if (l == r)RT re=0;
    RT re = max(A[l] - f(l + 1, r), A[r - 1] - f(l, r - 1));
}


void solve() {
    MEM(M, -1);

    cin >> N;
    rep(i, N)cin >> A[i];
    cout << f(0, N) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
