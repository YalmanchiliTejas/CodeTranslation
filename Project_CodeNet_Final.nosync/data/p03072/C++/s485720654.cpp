#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<ll, ll>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    int ans = 1;
    for (int i=1; i<N; ++i) {
        bool ok = true;
        for (int j=0; j<i; ++j) {
            if (H[j] > H[i]) ok = false;
        }
        ans += ok;
    }
    cout << ans << endl;
}
