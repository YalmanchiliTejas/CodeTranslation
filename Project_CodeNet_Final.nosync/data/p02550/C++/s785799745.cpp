#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1 << 30;


int main()
{
    ll k;
    cin >> k;
    int x,n;
    cin >> x >> n;
    vector<int> to(n);
    rep(i,n) to[i] = ((ll)i*i) % n;

    vector<int> seen(n,-1);
    vector<int> path(n);
    int s;
    int cur = x;
    int sz = 0;
    for(;;sz++) {
        if(seen[cur] != -1) {
            s = seen[cur];
            break;
        }
        else {
            seen[cur] = sz;
            path[sz] = cur;
            cur = to[cur];
        }
    }

    ll res = 0;
    if(k <= s) {
        rep(i,k) res += path[i];
        cout << res << endl;
    }
    else {
        rep(i,s) res += path[i];
        k = k - s;
        ll sum = 0;
        ll h = k / (ll)(sz-s);
        for(int i = s; i < sz; ++i) sum += path[i];
        res += (sum * h);
        ll w = k % (sz-s);
        for(int i = s; i < s + w; ++i) res += path[i];
        cout << res << endl;
    }
    return 0;
}