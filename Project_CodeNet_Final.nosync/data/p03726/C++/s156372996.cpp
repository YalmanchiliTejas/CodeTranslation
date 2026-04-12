#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
vector <int> v[maxn];
int dad[maxn];
long long dp[maxn];
bool visited[maxn];
int col[maxn];

int dfs(int x)
{
    visited[x] = 1;
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < v[x].size(); i++)
    {
        int u = v[x][i];
        if (!visited[u])
        {
            dad[u] = x;
            int ny = dfs(u);
            if(ny %2== 1)
            {
                tmp++;
            }
            ans += ny;
        }
        if(tmp > 1)
        {
            cout << "First";
            exit(0);
        }
    }
    return ans + 1;
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    long long n, m;
    cin >> n;

    m = n - 1;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (n %2== 1)
    {
        cout << "First";
        return 0;
    }
    dfs(0);
    cout << "Second";
}
