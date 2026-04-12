#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001;

int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};

int H,W,N;
char fld[55][55];

int D[50][50][50][50];

void bfs(int sy,int sx){
    fill_n(*D[sy][sx],2500,INF);
    D[sy][sx][sy][sx]=0;
    queue<pint>que;
    que.push(pint(sy,sx));
    while(que.size()){
        int y,x;
        tie(y,x)=que.front();
        que.pop();
        rep(i,4){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx]=='#'||D[sy][sx][ny][nx]!=INF)continue;
            D[sy][sx][ny][nx]=D[sy][sx][y][x]+1;
            que.push(pint(ny,nx));
        }
    }
}

int r[50][50],n[50][50],f[50][50];

vint ev[50][50];

int dp[1111][2];

int calc(vint vec,int r,int n,int f){
    fill_n(*dp,1111*2,INF);
    dp[0][0]=0;
    rep(i,vec.size()){
        int t=min(dp[i][0]+n,dp[i][1]+vec[i]*r);
        dp[i+1][0]=t+f;
        dp[i+1][1]=t-r*vec[i];
    }
    return dp[vec.size()][0];
}

signed main(){
    cin>>H>>W>>N;
    rep(i,H)cin>>fld[i];
    rep(i,H)rep(j,W)if(fld[i][j]=='.')bfs(i,j);


    rep(i,H)rep(j,W)cin>>r[i][j];
    rep(i,H)rep(j,W)cin>>n[i][j];
    rep(i,H)rep(j,W)cin>>f[i][j];

    int y,x;cin>>y>>x;
    ev[y][x].pb(0);
    int t=0;
    rep(i,N-1){
        int yy,xx;
        cin>>yy>>xx;
        while(y!=yy||x!=xx){
            int d=-1;
            rep(i,4){
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx]=='#')continue;
                if(D[y][x][yy][xx]==D[ny][nx][yy][xx]+1)d=i;
            }

            y+=dy[d];x+=dx[d];t++;
            ev[y][x].pb(t);
        }
    }

    int ans=0;
    rep(i,H)rep(j,W)ans+=calc(ev[i][j],r[i][j],n[i][j],f[i][j]);
    cout<<ans<<endl;
    return 0;
}