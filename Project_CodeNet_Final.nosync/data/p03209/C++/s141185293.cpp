#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
#define FOR(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define eFOR(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define rFOR(i,a,n) for(int (i)=(n)-1;(i)>=(a);(i)--)
#define erFOR(i,a,n) for(int (i)=(n);(i)>=(a);(i)--)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
#define all(i) (i).begin(),(i).end()
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T>inline istream& operator>>(istream& input, vector<T>& v) { for (auto& elemnt : v)input >> elemnt; return input; }

//厚さとパティの枚数のメモ化
ll t[51], p[51];

//レベルnの厚さ
ll thickness(int n) {
    if (t[n])return t[n];
    return t[n] = thickness(n - 1) * 2 + 3;
}

//レベルnのパティの枚数
ll patty(int n) {
    if (p[n])return p[n];
    return p[n] = patty(n - 1) * 2 + 1;
}

//レベルnの下からx層にあるパティの枚数
ll ans(int n, ll x) {
    if (n == 0) {
        if (x <= 0)return 0LL;
        return 1LL;
    }

    if (x <= 1 + thickness(n - 1)) {
        return ans(n - 1, x - 1);
    }
    if (x == 2 + thickness(n - 1)) {
        return patty(n - 1) + 1;
    }
    if (x <= 2 + thickness(n - 1) * 2) {
        return patty(n - 1) + 1 + ans(n - 1, x - 2 - thickness(n - 1));
    }
    if (x == 3 + thickness(n - 1) * 2) {
        return patty(n - 1) * 2 + 1;
    }
}

int main() {
    init();

    t[0] = 1, p[0] = 1;
    int n; ll x; cin >> n >> x;
    cout << ans(n, x) << "\n";
}
