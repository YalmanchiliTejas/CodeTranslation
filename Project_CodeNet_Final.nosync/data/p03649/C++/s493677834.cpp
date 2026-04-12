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
#define INF 9223372036854775807

int n,a[50],ans;
bool f=true;

signed main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    while(f) {
        f = false;
        int sum = 0;
        rep(i,n) sum += a[i]/n;
        rep(i,n) {
            int tmp = a[i]/n;
            a[i] += sum-a[i]/n*(n+1);
        }
        ans += sum;
        rep(i,n) if (a[i] >= n) f = true;
    }
    cout << ans << endl;
}

