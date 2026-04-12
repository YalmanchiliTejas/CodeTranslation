#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

int N;

int LIS(const vector<long long> &a) {
    int N = (int)a.size();
    vector<long long> dp(N, INF);
    for (int i = 0; i < N; ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    reverse(ALL(a));
    cout << LIS(a) << endl;
}