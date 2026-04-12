#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <set>
#define REP(i, n) for(i=0; i<n; i++)
#define REPR(i, n) for(i=n; i>=0; i--)
#define FOR(i, m, n) for(i=m; i<n; i++)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 10000000000
#define MAX 100000
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll, ll> P;

ll N, M;
bool G[8][8]={0};
ll ans=0;
bool visited[8]={0};

void bfs(ll s) {
    ll i;
    ll cnt=0;
    for(i=0; i<N; i++) {
        if(visited[i]) cnt++;
    }
    
    if(cnt==N) ans++;
    
    visited[s]=1;
    for(i=0; i<N; i++) {
        if(G[s][i] && !visited[i]) {
            visited[i]=1;
            bfs(i);
            visited[i]=0;
        }
    }
    
}

int main(void) {
    cin >> N >> M;
    ll i;
    ll a, b;
    for(i=0; i<M; i++) {
        cin >> a >> b;
        a--; b--;
        G[a][b]=1;
        G[b][a]=1;
    }
    visited[0]=1;
    bfs(0);
    cout << ans << endl;
}
