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

struct edge{
  int f,t,w;
};

ll A,B;
ll f[101][101];
ll dist[202][202];
ll d[10][10];
vector<edge> es;

int main(){
  cin>>A>>B;
  rep(i,A)rep(j,B)cin>>d[i][j];

  rep(i,101)rep(j,101){
    rep(a,A)rep(b,B){
      maxch(f[i][j],d[a][b]-i*(a+1)-j*(b+1));
    }
  }

  int S=0,T=201;
  rep(a,A)rep(b,B){
    rep(i,202)rep(j,202)dist[i][j]=(i==j?0:INF);
    rep(i,100)dist[i][i+1]=a+1;
    repl(i,101,201)dist[i][i+1]=b+1;
    rep(i,101)repl(j,101,202)dist[i][j]=f[i][201-j];
    rep(k,202)rep(i,202)rep(j,202)minch(dist[i][j],dist[i][k]+dist[k][j]);
    if(dist[S][T]!=d[a][b]){
      cout<<"Impossible"<<endl;
      return 0;
    }
  }
  cout<<"Possible"<<endl;
  rep(i,100)es.push_back((edge){i,i+1,-1});
  repl(i,101,201)es.push_back((edge){i,i+1,-2});
  rep(i,101)repl(j,101,202)es.push_back((edge){i,j,f[i][201-j]});
  cout<<202<<" "<<es.size()<<endl;
  rep(i,es.size()){
    cout<<es[i].f+1<<" "<<es[i].t+1<<" ";
    if(es[i].w==-1)cout<<"X";
    else if(es[i].w==-2)cout<<"Y";
    else cout<<es[i].w;
    cout<<endl;
  }
  cout<<S+1<<" "<<T+1<<endl;
  return 0;
}
