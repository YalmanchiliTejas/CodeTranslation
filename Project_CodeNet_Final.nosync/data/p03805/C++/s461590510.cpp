#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, k, n) for(int i = (int)k; i < (int)n; i++)
#define rrep(i, n) RREP(i, n, 0)
#define RREP(i, n, k) for(int i = (int)n-1; i > (int)k-1; i--)
#define mmax(start, end) *max_element(start, end)
#define mmin(start, end) *min_element(start, end)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " " << x << endl;

typedef long long ll;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M;
bool c[9][9] = {false};
int ans=0;

void dfs(int pos, vector<bool> open) {
    bool ok=true;
    REP(i,1,open.size()) if(open[i]) ok=false;
    if(ok) {
        ans++;
        return;
    }

    REP(i,2,10) {
        if(c[pos][i] && open[i]) {
            open[i] = false;
            dfs(i,open);
            open[i] = true;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    rep(i,M) {
        int a, b;
        cin >> a >> b;
        c[a][b] = c[b][a] = true;
    }

    vector<bool> arr = vector<bool>(N+1,true);
    arr[0]=arr[1]=false;

    dfs(1,arr);
    cout << ans << endl;
    return 0;
}
