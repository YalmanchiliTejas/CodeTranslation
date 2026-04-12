#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 998244353LL;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void) {
    llint n, x, m;
    cin >> n >> x >> m;

    llint now = x;
    vector<llint> visited(m, 0);
    vector<llint> path;
    while(visited[now]==0) {
        visited[now] = 1;
        path.push_back(now);
        now *= now;
        now %= m;
    }

    llint ans = 0;
    llint s = find(path.begin(), path.end(), now) - path.begin();
    llint r = path.size() - s;
    if(n<=r+s) {
        for(int in=0;in<n;++in) {
            ans += path[in];
        }
    }
    else {
        for(int is=0;is<s;++is) {
            ans += path[is];
        }
        llint sum = 0;
        for(int is=s;is<path.size();++is) sum += path[is];
        llint rep = (n - s) / r;
        llint g = (n - s) % r;
        ans += sum * rep;
        for(int ig=s;ig<g+s;++ig) {
            ans += path[ig];
        }
    }

    cout << ans << endl;
    return 0;
}
