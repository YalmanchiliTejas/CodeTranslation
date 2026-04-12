#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


vector<ll> a;

int main(){
    int n;
    cin >> n;
    rep(i, n){
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end(), greater<ll>());

    ll ans1 = 0;
    ll ans2 = 0;


    if (n%2 != 0){
        int m = n - 2;
        int l = (m + 1) / 2;
        int p = m - l;

        rep(i, n) {
            if (i < l) ans1 += 2 * a[i];
            else if (i < l + 2) ans1 -= a[i];
            else ans1 -= 2 * a[i];
        }
        rep(i, n) {
            if (i < p) ans2 += 2 * a[i];
            else if (i < p + 2) ans2 += a[i];
            else ans2 -= 2 * a[i];
        }
    }
    else {
        int m = n - 2;
        int l = m / 2;
        rep(i, n) {
            if (i < l) ans1 += 2 * a[i];
            else if (i < l + 1) ans1 += a[i];
            else if (i < l + 2) ans1 -= a[i];
            else ans1 -= 2 * a[i];
        }
    }

    cout << max(ans1, ans2) << endl;

    return 0;
}