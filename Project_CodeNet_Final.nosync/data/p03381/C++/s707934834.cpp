#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

int N;
vector<ll> X;
vector<ll> X_sorted;

int main(void) {
    cin >> N;

    rep(i, N) {
        ll a;
        cin >> a;
        X.push_back(a);
        X_sorted.push_back(a);
    }

    sort(ALLOF(X_sorted));

    REP(i, 0, N) {
        ll ans = 0;
        ll target = X[i]; // 1 origin
        // targetを見つける
        int ii = distance(X_sorted.begin(), lower_bound(ALLOF(X_sorted), target));

        if (ii < N / 2) {
            ans = X_sorted[N / 2];
        }
        else {
            ans = X_sorted[N / 2 - 1];
        }
        cout << ans << endl;
    }

    return 0;
}