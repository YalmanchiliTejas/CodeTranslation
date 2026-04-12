#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const double EPS = 1e-9;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<Pii> a(n);
    rep(n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));

    vector<int> ans(n);
    int ci = n/2;
    rep(n/2){
        ans[a[i].second] = a[ci].first;
    }
    reppp(i, n/2, n){
        ans[a[i].second] = a[ci-1].first;
    }

    rep(n){
        cout << ans[i] << endl;
    }
}
