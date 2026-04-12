#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define MOD 1000000007



int main() {
    int N;
    cin >> N;
    vi H(N);
    rep(i, N) cin >> H[i];

    int ans = 1;
    for (int i = 1; i < N; i++) {
        bool f = true;
        for (int j = 0; j < i; j++) {
            if (H[j] > H[i]) f = false;
        }
        if (f) ans++;
    }
    cout << ans << endl;

}
