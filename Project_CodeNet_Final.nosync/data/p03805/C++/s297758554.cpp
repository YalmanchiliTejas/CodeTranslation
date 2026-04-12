#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);i++)
#define erep(i,a,b) for(int i=a;i<=(int)(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>(a);i--)
#define eper(i,a,b) for(int i=((int)(a));i>=b;i--)
#define pb push_back
#define mp make_pair
#define INF (1<<30)-1
#define MOD 1000000007
using namespace std;
typedef long long ll;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int n, m, ans;
bool g[10][10];
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
    vector<int> v(n);
    rep(i, 0, n) v[i] = i;
    do {
        ans++;
        rep(i, 0, n-1) {
            int x, y;
            x = v[i];
            y = v[i+1];
            if (!g[x][y]) {
                ans--;
                break;
            }
        }
    } while (next_permutation(v.begin()+1, v.end()));
    printf("%d\n", ans);
    return 0;
}
