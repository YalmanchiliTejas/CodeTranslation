#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
vector<int> graph[10];
int v, e;
int dfs(int start, int depth, bool* seen)
{
    int ret = 0;
    int counter = 0;
    bool n_seen[8];
    for(int i = 0; i < 8; i++)n_seen[i] = seen[i];
    n_seen[start] = true;
    depth++;
    for (auto &&i : graph[start])
    {
        if(!n_seen[i])
        {
            ret+=dfs(i,depth,n_seen);
            counter++;
        }
    }
    if(counter == 0)
    {
        if(depth == v) ret = 1;
        else ret = 0;
    }
    return ret;
}
int main()
{
    
    cin >> v >> e;
    rep(i,e)
    {
        int from, to;
        cin >> from >> to;
        --from; --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    bool seen[8];
    rep(i,8)seen[i] = false;
    cout << dfs(0,0, seen) << endl;

}