#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int low[101], col[101];

int main(){
    int h, w;
    cin >> h >> w;
    char c[101][101];
    rep(i, h) rep(j, w) cin >> c[i][j];

    int cnt = 0;
    rep(i, h){
        bool flag = true;
        rep(j, w) if (c[i][j] == '#') flag = false;
        if (flag) low[i] = 1;
    }

    rep(j, w){
        bool flag = true;
        rep(i, h) if (c[i][j] == '#') flag = false;
        if (flag) col[j] = 1, cnt++;
    }


    rep(i, h){
        rep(j, w){
            if (!low[i] && !col[j]) cout << c[i][j];
        }
        if(!low[i]) cout << endl;
    }

    return 0;
}