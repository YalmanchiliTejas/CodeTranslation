#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<int> adjList[101010];
int cl[101010];

bool poss;

void dfs(int cur, int par) {
    for(auto nxt:adjList[cur])
        if(nxt != par)
            dfs(nxt, cur);
    if(cl[cur] == -1) {
        cl[cur] = 0;
        if(par == -1) {
            poss = false;
        }
        else if (cl[par] != -1) {
            poss = false;
        }
        else cl[par] = 1;
    }
}

int main()
{
    memset(cl,-1,sizeof(cl));
    poss = true;
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int ctr1 = 1; ctr1 < n; ctr1++) {
        cin>>a>>b;
        a--,b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfs(0,-1);
    if(!poss)
        cout<<"First";
    else cout<<"Second";
    return 0;
}
