#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    if(k == 0) {
        cout << (ll)n * n << endl;
        return 0;
    }
    
    ll ans = 0;
    FOR(i, 1, n + 1) {
        ans += n / i * max(0, i - k);
        ans += max(0, n % i - k + 1);
    }
    cout << ans << endl;

    return 0;
}