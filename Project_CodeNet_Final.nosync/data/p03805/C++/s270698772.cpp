#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(ll i=0; i<(ll)(n); i++)
#define FOR(i,n,m) for (ll i=n; i<(ll)(m); i++)
#define pb push_back
#define INF 1000000007LL
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int,int> p;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

int N, M;
int adj[8][8];
int cnt = 0;

void dfs(int state, int place) {
    if (state == int(1<<N)-1) {
        cnt++;
        return;
    }
    REP(i,N) {
        if ( (state>>i&1) != 1 && adj[place][i]) {
            dfs(state+(1<<i),i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i,M) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    dfs(1,0);
    cout << cnt << endl;
    
    return 0;
}