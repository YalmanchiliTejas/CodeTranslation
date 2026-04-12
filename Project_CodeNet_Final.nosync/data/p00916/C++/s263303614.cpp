#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

ll n;
ll a[55],b[55],c[55],d[55];
vector<ll> xs,ys;
bool w[500][500];
bool vis[500][500];
ll dd[]={-1,0,1,0,-1};

int main(){
  while(1){
    cin>>n;
    if(n==0)break;
    rep(i,n){
      cin>>a[i]>>d[i]>>c[i]>>b[i];
      a[i]*=2; d[i]*=2; c[i]*=2; b[i]*=2;
    }

    xs.clear();
    ys.clear();
    rep(i,n){
      xs.push_back(a[i]+1);
      xs.push_back(a[i]);
      xs.push_back(a[i]-1);
      xs.push_back(c[i]+1);
      xs.push_back(c[i]);
      xs.push_back(c[i]-1);
    }
    rep(i,n){
      ys.push_back(b[i]+1);
      ys.push_back(b[i]);
      ys.push_back(b[i]-1);
      ys.push_back(d[i]+1);
      ys.push_back(d[i]);
      ys.push_back(d[i]-1);
    }
    sort(all(xs));
    uni(xs);
    sort(all(ys));
    uni(ys);
    memset(w,0,sizeof(w));
    rep(i,n){
      a[i]=lower_bound(all(xs),a[i])-xs.begin();
      c[i]=lower_bound(all(xs),c[i])-xs.begin();
      b[i]=lower_bound(all(ys),b[i])-ys.begin();
      d[i]=lower_bound(all(ys),d[i])-ys.begin();
      repl(y,b[i],d[i]+1){
        w[y][a[i]]=true;
        w[y][c[i]]=true;      
      }
      repl(x,a[i],c[i]+1){
        w[b[i]][x]=true;
        w[d[i]][x]=true;      
      }
    }
    ll res=0;
    memset(vis,0,sizeof(vis));
    rep(i,500)rep(j,500){
      if(vis[i][j]||w[i][j])continue;
      res++;
      queue<P> que;
      que.push(P(i,j));
      while(que.size()){
        P p=que.front(); que.pop();
        ll ci=p.fi,cj=p.se;
        rep(d,4){
          ll ni=ci+dd[d],nj=cj+dd[d+1];
          if(ni>=0&&ni<500&&nj>=0&&nj<500&&!vis[ni][nj]&&!w[ni][nj]){
            vis[ni][nj]=true;
            que.push(P(ni,nj));
          }
        }
      }
    }
    cout<<res<<endl;
  }
  return 0;
}

