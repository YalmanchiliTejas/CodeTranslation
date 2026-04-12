#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
typedef long double ld;
typedef long long int ll;
const ll INF = (1LL << 63);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0; i < n;i++)
const int MAX = 1000000010;
const ll MOD = 1000000007;
ll h, w, t,n,q,x,sum = 0;
vector<vector<ll>> dp;
vector<ll> a;
ll rec(int l, int r) {
    if (r == l) return 0;
    ll &ret = dp[l][r];
    if (ret != INF) return ret;
    if ((n - r + l) % 2 == 0) {
        ret = max(a[l] + rec(l + 1, r), rec(l, r - 1) + a[r - 1]);
    }
    else {
        ret = min(-a[l] + rec(l + 1, r), rec(l, r - 1) - a[r - 1]);
    }return ret;
}
int main() {
    cin >> n;
    a.resize(n);
    dp.resize(n + 5, vector<ll>(n + 5, INF));
    rep(i, n + 1)dp[i][i] = 0;
    rep(i, n) cin >> a[i];
    cout << rec(0, n) << endl;
}