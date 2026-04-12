#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end())
#define vdelete(v) (v).erase(unique(all(v)), (v).end())
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1000000007
#define INF LONG_LONG_MAX

#define P pair<int,int>

int n,x,y,max_min=INF,min_max,MIN=INF,MAX,ans;
vector<P> v;

signed main() {
    cin >> n;
    rep(i,n) {
        cin >> x >> y;
        if (x > y) swap(x,y);
        v.pb(mp(x,y));
        MIN = min(MIN,x);
        MAX = max(MAX,y);
        max_min = min(max_min,y);
        min_max = max(min_max,x);
    }
    ans = (min_max - MIN) * (MAX - max_min);
    sort(all(v));
    int ma = max(v[0].se, v[n-1].fi), mi = v[0].se;
    rep11(i,n) {
        ans = min(ans, (MAX-MIN) * (ma - min(mi,v[i].fi)));
        ma = max(ma, v[i].se);
        mi = min(mi, v[i].se);
    }
    cout << ans << endl;
}

