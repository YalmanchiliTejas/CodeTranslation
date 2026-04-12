#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
# define rep(i, n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
# define all(x) (x).begin(), (x).end()

ll N;
ll M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    vector<ll> a(M);
    vector<ll> b(M);
    rep(i, M) {
        cin >> a[i];
        a[i]--;
        cin >> b[i];
        b[i]--;
    }

    vector<ll> p(N);
    rep(i, N) {
        p[i] = i;
    }

    bool d[N][N];
    memset(d, false, sizeof(d));
    rep(i, M) {
        d[a[i]][b[i]] = true;
        d[b[i]][a[i]] = true;
    }

    ll cnt = 0;
    do {
        if(p[0] != 0) {
            continue;
        }

        bool flag = true;

        rep(i, N-1) {
            if (!d[p[i]][p[i+1]]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cnt++;
        }
    } while(next_permutation(all(p)));

    cout << cnt << endl;
    return 0;
}
