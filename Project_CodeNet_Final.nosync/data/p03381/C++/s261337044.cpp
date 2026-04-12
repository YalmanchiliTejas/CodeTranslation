#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef string str;
const long long INF = INT64_MAX;

#define REP(i, n) for(ll i=0;i<n;i++)
#define ASC(v) sort((v).begin(), (v).end())
#define DESC(v) sort((v).rbegin(), (v).rend())
#define INV(v) reverse((v).rbegin(), (v).rend())
#define FOLDL(src, dst, lambda) partial_sum((src).begin(), (src).end(), (dst).begin(), lambda)
#define FOLDR(src, dst, lambda) INV(src);partial_sum((src).begin(), (src).end(), (dst).begin(), lambda);INV(dst)
#define DESC(v) sort((v).rbegin(), (v).rend())
#define ERASE(v, i) v.erase(v.begin() + i)
#define UNIQ(v) ASC(v);erase(unique(v.begin(), v.end()), v.end())
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve() {
    ll N;
    cin >> N;
    vll A(N);
    for(auto &a:A) cin >> a;
    vpll vp;
    for(int i = 0; i < N; i++) {
        vp.push_back(make_pair(A[i], i));
    }
    ASC(vp);
    vll ans(N);
    for(int i = 0; i < N; i++) {
        ll idx = vp[i].second;
        ans[idx] = vp[N/2 - (i >= (N / 2) ? 1 : 0)].first;
    }
    for(auto &a:ans) {
        cout << a << endl;
    }
}

int main() {
    FIO;
    solve();
    return 0;
}
