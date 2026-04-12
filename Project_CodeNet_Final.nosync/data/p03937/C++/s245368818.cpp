#include<bits/stdc++.h>
#include<climits>
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define ROF(i,a,b) for(int i = (a);i>=(b);i--)
#define MST(a,x) memset(a,x,sizeof(a))
#define ll long long
#define PB push_back
#define PH push
#define MP make_pair
#define FT first
#define SD second
#define N 105
#define M 10005
//#define INF
#define MOD 1000000007
#define MOD2 1000000009
#define eps 1e-7
using namespace std;
const ll INF = ~1ull>>1;
inline int Max(int a,int b)
{
    return (((b-a)>>(32-1))&(a^b))^b;
}
inline int Min(int a,int b)
{
    return (((b-a)>>(32-1))&(a^b))^a;
}
int is_mul_overflow(ll a, ll b) {
        return LLONG_MAX / a < b;
}

string s[N];
int vis[N][N];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        MST(vis,0);
        FOR(i,0,n-1)cin>>s[i];
        int x = 0,y = 0,f = 1;
        vis[x][y] = 1;
        while(x!=n-1||y!=m-1)
        {
            if(x+1<n&&s[x+1][y] == '#')x++;
            else if(y+1<m&&s[x][y+1] == '#')y++;
            else
            {
                f = 0;
                break;
            }
            vis[x][y] = 1;
        }
        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                //if(vis[i][j])cout<<i<<" "<<j<<" "<<vis[i][j]<<endl;
                if(s[i][j] == '#'&&vis[i][j] == 0)f = 0;
                if(s[i][j] != '#'&&vis[i][j] == 1)f = 0;
            }
        }
        if(f)cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
