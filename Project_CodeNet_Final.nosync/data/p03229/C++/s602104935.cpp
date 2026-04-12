#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
#define FOR(i,a,n) for(int (i)=(a);(i)<(n);++(i))
#define eFOR(i,a,n) for(int (i)=(a);(i)<=(n);++(i))
#define rFOR(i,a,n) for(int (i)=(n)-1;(i)>=(a);--(i))
#define erFOR(i,a,n) for(int (i)=(n);(i)>=(a);--(i))
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
#define all(i) (i).begin(),(i).end()
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }
template<class T> inline istream& operator>>(istream& input, vector<T>& v) { for (auto& elemnt : v)input >> elemnt; return input; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }

int main() {
    init();

    int n; cin >> n;
    VL a(n); cin >> a;

    VL x(n, 0), y(n, 0);
    FOR(i, 1, n) {
        if (i % 2) {
            x[i - 1]++, x[i]--;
            y[i - 1]--, y[i]++;
        }
        else {
            x[i - 1]--, x[i]++;
            y[i - 1]++, y[i]--;
        }
    }
    SORT(a), SORT(x), SORT(y);

    ll X = 0, Y = 0;
    FOR(i, 0, n) {
        X += a[i] * x[i];
        Y += a[i] * y[i];
    }

    cout << max(X, Y) << "\n";
}
