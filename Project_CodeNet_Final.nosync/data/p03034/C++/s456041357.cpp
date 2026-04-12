#include <bits/stdc++.h>
using namespace std;

struct Benri {
    Benri() {
        std::cin.tie(0); ios::sync_with_stdio(false);
        cout << fixed << setprecision(12);
    }
} benri;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
const int INF = 1 << 28;




int main() {
    int N; cin >> N;
    vll s(N);
    rep(i, N) cin >> s[i];

    ll sum;
    ll ans = 0;

    for (int c = 1; c <= N - 1 ; c++ ) {
        sum = 0;
        int j = 1;
        if ((N - 1) % c != 0 ) {
            while (j * c < N - 1 && N - 1 - j * c > c) {
                sum += s[j * c] + s[N - 1 - j * c];
                chmax(ans, sum);
                j++;
            }
        }
        else {
            while (j * c <  N - 1 - j * c) {
                sum += s[j * c] + s[N - 1 - j * c];
                chmax(ans, sum);
                j++;
            }
        }
    }

    cout << ans << endl;
}
