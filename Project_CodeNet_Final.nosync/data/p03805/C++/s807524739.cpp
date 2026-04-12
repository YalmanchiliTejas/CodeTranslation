#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<vector<int>>v;
vector<bool>f;
int nummmmm;

void dfs(int p)
{
    bool end = true;
    for(int i = 0; i < N; i++)
    {
        if(!f[i] && i != p) end = false;
    }
    if(end) 
    {
        nummmmm++;
        return;
    }
    f[p] = true;
    for(auto np:v[p])
    {
        if(f[np]) continue;
        dfs(np);
    }
    f[p] = false;
}

int main()
{
    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < M; i++)
    {
        int a,b;
        cin >> a >> b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    nummmmm = 0;
    f.assign(N,false);
    dfs(0);
    cout << nummmmm << endl;
    return 0;
}