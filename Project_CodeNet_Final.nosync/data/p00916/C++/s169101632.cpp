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

int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};

int N;
int y[50],x[50],yy[50],xx[50];
vint ys,xs;

int col[200][200];
bool used[200][200];

void solve(){
    ys.clear();xs.clear();
    rep(i,N){
        cin>>x[i]>>yy[i]>>xx[i]>>y[i];
        ys.pb(y[i]);ys.pb(yy[i]);
        xs.pb(x[i]);xs.pb(xx[i]);
    }
    xs.pb(-1001001001);ys.pb(-1001001001);

    sort(all(xs));xs.erase(unique(all(xs)),xs.end());
    sort(all(ys));ys.erase(unique(all(ys)),ys.end());
    rep(i,N){
        x[i]=lower_bound(all(xs),x[i])-xs.begin();
        y[i]=lower_bound(all(ys),y[i])-ys.begin();

        xx[i]=lower_bound(all(xs),xx[i])-xs.begin();
        yy[i]=lower_bound(all(ys),yy[i])-ys.begin();
    }

    for(int i=0;i<ys.size();i++){
        for(int j=0;j<xs.size();j++){
            int b=0;
            rep(k,N){
                b<<=1;
                if(x[k]<=j&&j<xx[k]&&y[k]<=i&&i<yy[k])b++;
            }
            col[i][j]=b;
        }
    }

    memset(used,0,sizeof(used));
    int ans=0;
    rep(i,ys.size())rep(j,xs.size()){
        if(used[i][j])continue;
        queue<pint>que;
        used[i][j]=true;
        ans++;
        que.push({i,j});
        while(que.size()){
            int y,x;
            tie(y,x)=que.front();
            que.pop();
            rep(d,4){
                int ny=y+dy[d],nx=x+dx[d];
                if(ny<0||ny>=ys.size()||nx<0||nx>=xs.size()||col[y][x]!=col[ny][nx]||used[ny][nx])continue;
                used[ny][nx]=true;
                que.push({ny,nx});
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    while(cin>>N,N)solve();
}