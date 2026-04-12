#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
#define mk make_pair
#define pb push_back
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;

int N, M;
vector<int> G[10];
bool used[10];

int dfs(int v)
{
    used[v] = true;
    int res = 0;
    for(int i = 0; i < (int)G[v].size(); i++){
        if(!used[G[v][i]])res += dfs(G[v][i]);
    }
    if(res == 0){
        int ret = 1;
        for(int i = 0; i < N; i++){
            if(!used[i])ret = 0;
        }
        used[v] = false;
        return ret;
    }
    used[v] = false;
    return res;
}

signed main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    cout << dfs(0) << endl;

    return 0;
}

/*



*/
