#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
#define ALL(x) x.begin(),x.end()
typedef pair<int, int> P;
typedef long long ll;

int N, M;
int V[10][10];
int pass[10];
int ans;

void solve(int i, int t) {

    if (t == N) {
        bool ok = true;
        rep(v, N) {
            if (!pass[v]) ok = false;
        }
        if (ok) ans++;
        return;
    }

    rep(v, N) {
        if (V[i][v] && !pass[v]) {
            pass[v] = true;
            solve(v, t+1);
            pass[v] = false;
        }
    }

}

int main() {
    cin >> N >> M;
    rep(i,M) {
        int a, b; cin >> a >> b; --a; --b;
        V[a][b] = 1;
        V[b][a] = 1;
    }
    fill(pass, pass+N, false);
    pass[0] = true;
    solve(0, 1);
    cout << ans << endl;
    return 0;
}
