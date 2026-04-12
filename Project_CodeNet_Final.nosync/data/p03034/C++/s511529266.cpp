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

void solve() {
    int N;
    cin >> N;
    vll s(N);
    rep(i, N)cin >> s[i];

    ll ans = LLONG_MIN;
    set<int> T;
    for (int i = 1; i <= N - 1; ++i) { // A-B
        T.clear();
        ll sum = 0;
        for (int j = 0; i*j < N - 1; ++j) { // j turns
            int A = N - 1 - i * j;
            int B = A - i;
            if (B <= 0)break;
            if (T.count(i*j))break;
            T.insert(i*j);
            sum += s[i*j];
            if (T.count(N - 1 - i * j))break;
            T.insert(N - 1 - i * j);
            sum += s[N - 1 - i * j];
            smax(ans, sum);
        }
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}