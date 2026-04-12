#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    vector<int> cnt(n);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        d[a].push_back(b);
        d[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    queue<int> que;
    for(int i = 0; i < n; i++)
    {
        if(d[i].size() == 1) que.push(i);
    }
    bitset<100000> bs;
    bool flag = true;
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        if(bs[v]) continue;
        bs[v] = 1;
        int nv = -1;
        for(int nx : d[v])
        {
            if(bs[nx]) continue;
            nv = nx;
        }
        if(nv == -1)
        {
            flag = false;
            break;
        }
        bs[nv] = 1;
        for(int nnx : d[nv])
        {
            if(bs[nnx]) continue;
            cnt[nnx]--;
            if(cnt[nnx] == 1) que.push(nnx);
        }
    }
    if(flag) cout << "Second" << endl;
    else cout << "First" << endl;
}
