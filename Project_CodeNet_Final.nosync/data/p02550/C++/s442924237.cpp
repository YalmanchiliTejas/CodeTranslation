#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;
template<typename T>
struct Edge {
    int u, v;
    T cost;
    Edge(int u, int v, T c) : u(u), v(v), cost(c) {}
    bool operator< (const Edge &e) const {return cost < e.cost;}
};

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

ll ans;
ll used[100005], S[100005];

int main(void) {
    ll N, X, M;
    cin >> N >> X >> M;
    ll now = X%M;
    ll s=-1, t=-1;
    for (int i=0; i<=100005; i++) used[i] = -1;
    for (ll i=1; i<=N; i++) {
        if (used[now]!=-1) {
            s = (ll)used[now];
            t = (ll)i;
            break;
        }
        used[now] = i;
        S[i] = S[i-1] + now;
        now = (now*now)%M;
        
    }

    if (s==-1 && t==-1) ans = S[N]-S[0];
    else {
        ll L = t-s, k = N-s+1;
        ll Q = k/L, R = k%L;
        ans = (S[s-1]-S[0])+(S[t-1]-S[s-1])*Q+(S[s+R-1]-S[s-1]);
    }

    
    cout << ans << endl;
    return 0;
}



