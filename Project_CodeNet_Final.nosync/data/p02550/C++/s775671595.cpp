#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)

int N, X, M;
int nxt[100010][60];
int cost[100010][60];

signed main()
{
    cin >> N >> X >> M;

    rep(i, M)nxt[i][0] = i * i % M;
    for(int i = 1; i < 60; i++)
    {
        rep(j, M)nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
    }

    rep(i, M)cost[i][0] = i;
    for(int i = 1; i < 60; i++)
    {
        rep(j, M)cost[j][i] = cost[j][i - 1] + cost[nxt[j][i - 1]][i - 1];
    }

    int ans = 0;
    int now = X;
    rep(i, 60)
    {
        if(N & (1LL << i))
        {
            ans += cost[now][i];
            now = nxt[now][i];
        }
    }

    cout << ans << endl;

    return 0;
}
