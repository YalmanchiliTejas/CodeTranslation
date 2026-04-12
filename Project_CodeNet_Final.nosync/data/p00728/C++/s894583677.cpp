#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define int long long
using namespace std;
typedef long long int64;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e18 * 5;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    while(n != 0){
        vector<int> s(n);
        REP(i, n) cin >> s[i];
        int sum = accumulate(All(s), 0);
        sum -= *max_element(All(s)) + *min_element(All(s));
        sum /= (n-2);
        cout << sum << "\n";

        cin >> n;
    }
    return 0;
}
