#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long
#define all(_v) _v.begin(), _v.end()
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pvllvll pair <vector <ll>, vector <ll> >
#define ld long double
#define veci vector <int>
#define vecll vector <ll>


const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const double PI = 3.1415926535897932384626433832795;
const double eps = 1e-9;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    veci a(n), pref(n);
    for(auto &it : a) cin >> it;
    int sum = 0;
    for(int i = 0; i < n; ++i) pref[i] = (!i ? a[i] : (pref[i - 1] + a[i]) % MOD1);
    for(int i = 0; i < n - 1; ++i)
        sum = (sum + a[i] * 1ll * ((pref[n - 1] - pref[i] + MOD1) % MOD1) % MOD1) % MOD1;
    cout << sum;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
    ///cin >> T;
    while(T--) solve(), cout << '\n';
    return 0;
}
