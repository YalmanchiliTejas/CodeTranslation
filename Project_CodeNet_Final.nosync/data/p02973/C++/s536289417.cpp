#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define fi first
#define se second
#define FF first
#define SS second
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define endl '\n'
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(x) (int)x.size()
typedef long double f80;
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

multiset<int> s;

signed main()
{
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    fr(i, 1, n) {
        int x;
        cin >> x;
        auto it = s.lower_bound(x);
        if(it != s.begin()) {
            it--;
            s.erase(it);
        }
        s.insert(x);
    }
    cout << sz(s);
    return 0;
}