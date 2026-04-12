#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int h, w;
char c[1000][1000];
vector<int> v1, v2;

int main() {
    cin >> h >> w;
    rep(i,h) rep(j,w) cin >> c[i][j];
    rep(i,h) rep(j,w) {
        if (c[i][j] != '.') v1.push_back(i+j);
        if (c[i][j] != '.') v2.push_back(i-j);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans = max(v1[v1.size()-1] - v1[0], v2[v2.size()-1] - v2[0]);
    cout << ans << endl;
}

