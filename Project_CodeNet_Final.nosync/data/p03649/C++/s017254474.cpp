#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))

#define MOD 1000000007
#define INF 1000000000
#define MAX_N 55

ll N;
vector<ll> a;

int main()
{
    cin >> N;
    REP(i, N) {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    //sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    while(1) {
        vector< pair<int, ll> > change;     // インデックス, 足す値
        REP(i, N) {
            if(a[i] >= N) {
                ll tmp = a[i] / N;
                a[i] = a[i] % N;
                change.push_back(make_pair(i, tmp));
                ans += tmp;
            }
        }
        if(change.size() == 0) { break; }
        REP(i, change.size()) {
            REP(j, N) {
                if(change[i].first != j) {
                    a[j] += change[i].second;
                }
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
