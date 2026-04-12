#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001

bool dp[2][1 << 16];
vector<int> nxt[1 << 16];

int main(){
    cin.sync_with_stdio(false);
    int n, m, k, tmp;
    cin >> n >> m >> k;

    int bright[n] = {};
    int dark[m];
    rep(i, n) bright[i] = -1;
    rep(i, m) {
        cin >> dark[i];
        bright[--dark[i]] = i;
    }

    int to[n][k];
    rep(i, n) {
        rep(j, k) {
            cin >> to[i][j];
            to[i][j]--;
        }
    }

    rep(i, 1 << m) {
        int a[k] = {};
        rep(j, m) {
            if (i & (1 << j)) {
                rep(l, k) {
                    if (bright[to[dark[j]][l]] >= 0) {
                        a[l] |= (1 << bright[to[dark[j]][l]]);
                    }
                }
            }
        }
        rep(j, k) nxt[i].pb(a[j]);
    }

    memset(dp, 0, sizeof(dp));
    tmp = 0;
    dp[tmp % 2][(1 << m) - 1] = true;
    while(!dp[tmp % 2][0]) {
        rep(i, 1 << m) {
            if (dp[tmp % 2][i]) {
                rep(j, nxt[i].size()) dp[(tmp + 1) % 2][nxt[i][j]] = true;
            }
            dp[tmp % 2][i] = false;
        }
        tmp++;
    }
    cout << tmp << endl;

    return 0;
}