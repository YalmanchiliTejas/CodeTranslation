#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(b);i>(a);--i)
#define eper(i,a,b) for(int i=((int)(a));i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}

int n, m, ans;
bool g[100][100], d[100];

void dfs(int v) {
    d[v] = true;
    bool all_visited = true;
    rep(i, 0, n) {
        if (!d[i]) {
            all_visited = false;
            break;
        }
    }
    if (all_visited) {
        ans++;
        return;
    }

    rep(i, 0, n) {
        if (v == i) continue;
        if (!d[i] && g[v][i]) {
            d[i] = true;
            dfs(i);
            d[i] = false;
        }
    }
    return;
}

int main() {
 ios::sync_with_stdio ( false );
 cin.tie ( 0 );
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = true;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
