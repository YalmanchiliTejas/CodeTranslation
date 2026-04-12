#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
#define eb emplace_back
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
#define outl2(x,y) cout<< (x) << ' ' << (y) << '\n'
#define show(x) clog << #x << " \t = " << (x) << '\n'
using pii = pair<int,int>;
using ll = long long;
template<class A, class B>inline bool chmax(A &a, B b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, B b){return b<a ? a=b,1 : 0;}
static constexpr int INF = 0x3f3f3f3f;

vector<int> G[10];
int N, M;
int dp[10][1 << 9];

int _(int u, int bit)
{
    if (bit == (1 << N)-1) {
        return 1;
    }
    if (~dp[u][bit]) return dp[u][bit];

    int ret = 0;

    for (int nxt : G[u]) {
        if ((bit >> nxt) & 1) continue;
        ret += _(nxt, bit | (1 << nxt));
    }

    return dp[u][bit] = ret;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(false);

    cin>> N >> M ;
    rep(i, M) {
        int a,b;
        cin >> a >> b;
        --a, --b;
        G[a].eb(b);
        G[b].eb(a);
    }

    memset(dp, -1, sizeof(dp));

    outl(_(0,1));

    return 0;
}

