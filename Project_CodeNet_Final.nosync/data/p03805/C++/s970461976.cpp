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
#define mkp make_pair
#define pr(num) cout << num << "\n"
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 100010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll N, M;
vector<ll> g[11];
ll ans;
ll used[11];

void dfs(ll s) {
    used[s]=1;
    ll i;
    ll flag=1;
    for(i=0; i<N; i++) {
        if(used[i]==0) flag=0;
    }
    
    if(flag) {
        ans++;
        used[s]=0;
        return;
    }
    
    for(i=0; i<g[s].size(); i++) {
        if(used[g[s][i]]) continue;
        dfs(g[s][i]);
    }
    
    used[s]=0;
}

int main(void) {
    ll i;
    cin >> N >> M;
    
    for(i=0; i<M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(0);
    pr(ans);
    
}













