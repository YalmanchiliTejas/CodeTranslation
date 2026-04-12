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

    int n;
    cin >> n;
    vi a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    
    ll ans = 0;
    if(n % 2 == 0) {
        ll sum = 0;
        REP(i, n / 2 - 1) sum -= 2 * a[i];
        sum += -a[n / 2 - 1] + a[n / 2];
        FOR(i, n / 2 + 1, n) sum += 2 * a[i];
        cout << sum << endl;
        return 0;
    }
    // nが奇数
    ll sum = 0;
    REP(i, (n-1) / 2) sum -= 2 * a[i];
    sum += a[(n-1)/2] + a[(n+1)/ 2] ;
    FOR(i, (n+1)/2 + 1, n) sum += 2 * a[i];
    ans = sum;
    
    sum = 0;
    REP(i, (n-3) / 2) sum -= 2 * a[i];
    sum -= a[(n-3)/2] + a[(n-1)/ 2] ;
    FOR(i, (n-1)/2 + 1, n) sum += 2 * a[i];   
    ans = max(ans, sum);
    cout << ans << endl;


    return 0;
}