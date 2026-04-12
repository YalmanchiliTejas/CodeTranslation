#include <bits/stdc++.h>
using namespace std;

#define rep2(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) rep2(i,0,n)
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
    cout << std::fixed << std::setprecision(10);
    
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    int ans = 0;
    int hmax = 0;
    rep(i, n) {
        if(a[i] >= hmax) ans++;
        hmax = max(hmax, a[i]);
    }
    cout << ans << endl;
    

    return 0;
}