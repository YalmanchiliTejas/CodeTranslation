#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N;
pii X[200200];
int ans[200200];

signed main() {
    cin >> N;
    rep(i, N) {
        int x;
        cin >> x;
        X[i] = pii(x, i);
    }
    sort(X, X + N);
    rep(i, N / 2) {
        ans[X[i].second] = X[N / 2].first;
    }
    for (int i = N / 2; i < N; ++i) {
        ans[X[i].second] = X[N / 2 - 1].first;
    }
    rep(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}
