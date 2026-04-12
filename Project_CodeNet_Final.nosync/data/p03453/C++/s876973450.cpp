#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   mod = 1e9 + 7;
const int   N   = 1e5 + 5;

typedef pair<ll,int>    ii;

void add(int &a,int b)  {
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub(int &a,int b)  {
    a -= b;
    if (a <  0)
        a += mod;
}
int mul(int a,int b)    {   return  1ll * a * b % mod;  }
int Pow(int a,int b)    {
    int ans = 1;
    while  (b)  {
        if (b & 1)  ans = mul(ans,a);
        a = mul(a,a);   b >>= 1;
    }
    return  ans;
}
vector<ii>  g[N];

ll  dis[2][N];
int cnt[2][N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;   cin >> n >> m;
    int S, T;   cin >> S >> T;

    for(int i = 0 ; i < m ; ++i)    {
        int x;  cin >> x;
        int y;  cin >> y;
        int c;  cin >> c;

        g[x].pb(c,y);
        g[y].pb(c,x);
    }

    for(int t = 0 ; t < 2 ; ++t)    {
        priority_queue<ii,vector<ii>,greater<ii> >  pq;

        fill(dis[t] + 1,dis[t] + 1 + n,1e18);

        if (t)  dis[1][T] = 0, cnt[1][T] = 1,   pq.push(ii(0,T));
        else    dis[0][S] = 0, cnt[0][S] = 1,   pq.push(ii(0,S));

        while (pq.size())   {
            int u  = pq.top().Y;
            ll  du = pq.top().X;    pq.pop();

            if (dis[t][u] != du)
                continue;

            for(ii  e : g[u])   {
                int v = e.Y;

                if (dis[t][v] > du + e.X)   {
                    dis[t][v] = du + e.X;
                    cnt[t][v] = 0;
                    pq.push(ii(dis[t][v],v));
                }
                if (dis[t][v] == du + e.X)
                    add(cnt[t][v],cnt[t][u]);
            }
        }
    }
    int ans = mul(cnt[0][T],cnt[0][T]);

    for(int i = 1 ; i <= n ; ++i)   {
        if (dis[0][i] * 2 == dis[0][T]) {
            int val = 1;
            val = mul(val,mul(cnt[0][i],cnt[0][i]));
            val = mul(val,mul(cnt[1][i],cnt[1][i]));

            sub(ans,val);
        }
        for(ii  e : g[i])   {
            int v = e.Y;
            int w = e.X;

            if (dis[0][i] + w + dis[1][v] != dis[0][T]) continue;
            
            if (dis[0][i] * 2 >= dis[0][T]) continue;
            if (dis[1][v] * 2 >= dis[0][T]) continue;

            int val = 1;

            val = mul(val,mul(cnt[0][i],cnt[0][i]));
            val = mul(val,mul(cnt[1][v],cnt[1][v]));

            sub(ans,val);
        }
    }
    cout << ans << endl;
}