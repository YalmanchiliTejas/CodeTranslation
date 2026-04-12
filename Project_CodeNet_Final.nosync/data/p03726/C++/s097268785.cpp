#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using  namespace  std;

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define mod 1000000007
#define ull unsigned long long
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define mst(ss,b) memset(ss,b,sizeof(ss));
#define dbg(x) cout << #x << "= " << x << endl;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll INF = (1LL<<63)-1;
const int N = 1e5+5;

int n;
vector<int>E[N];
int col[N];

void dfs(int u, int fa){
    for(auto v : E[u]){
        if(v == fa)continue;
        dfs(v, u);
    }
    if(!col[u] && !col[fa])col[u] = col[fa] = 1;
}

int  main(){
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].pb(v);
        E[v].pb(u);
    }
    col[0] = 1;
    dfs(1, 0);
    int fg = 0;
    for(int i=1; i<=n; i++)if(!col[i])fg = 1;
    puts(fg?"First":"Second");
    return 0;
}


// lower_bound()
// __builtin_popcount()
// ios::sync_with_stdio(false);
// freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
// const double eps=1e-12;
// #pragma comment(linker,"/STACK:102400000,102400000")
