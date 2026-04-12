#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define fi first
#define se second
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = 1; i < (n); ++i)
#define drep(i,n) for (int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define all(x) (x).begin(), (x).end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T> >

//#define v(T) vector<T>
//#define vv(T) v(v(T))

using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
//typedef vector<int> vi;
//typedef vector<vi> vvi;
//typedef vector<ll> vl;
//typedef vector<P> vp;

const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> to[10];
    int a, b;
    rep(i,m) {
        cin >> a >> b;
        --a; --b;
        to[a].pb(b);
        to[b].pb(a);
    }

    vector<int> v(n-1);
    rep(i,n-1) v[i] = i+1;
    int ans = 0;
    do {
        int pre = 0;
        bool ok = true;
        for(auto i: v) {
            auto itr = find(all(to[pre]), i);
            if (itr == to[pre].end()) ok = false;
            pre = i;
        }
        if (ok) ++ans;
    } while(next_permutation(all(v)));
    cout << ans << endl;
    return 0;
}
