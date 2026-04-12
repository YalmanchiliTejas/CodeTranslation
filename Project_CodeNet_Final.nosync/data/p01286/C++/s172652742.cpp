#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000

typedef long long LL;
typedef long double LD;

class FordFulkerson{
  vector<vector<int>> e;
  vector<bool> usd;
  int n,s,t;
public:
  FordFulkerson(vector<vector<int>> &v,int ss,int tt){
    e=v,s=ss,t=tt,n=v.size();
  }
  int solve(){
    int ans=0,ret;
    usd=vector<bool>(n,false);
    while(1){
      usd=vector<bool>(n,false);
      ret=dfs(s);
      if(ret==0) break;
      else ans+=ret;
    }
    return ans;
  }
  int dfs(int x,int d=INF){
    usd[x]=true;
    int ret;
    for(int i=0;i<n;i++){
      if((!usd[i])&&e[x][i]>0){
        if(i==t){
          ret=min(d,e[x][i]);
          e[x][i]-=ret;
          e[i][x]+=ret;
          return ret;
        }else{
          ret=dfs(i,min(d,e[x][i]));
          if(ret>0){
            e[x][i]-=ret;
            e[i][x]+=ret;
            return ret;
          }
        }
      }
    }
    return 0;
  }
};

int main(){
  while(1){
    int h,w,c,m,nw,nc,nm;
    cin >> h >> w >> c >> m >> nw >> nc >> nm;
    if(h<0) return 0;
    int sz=308;
    vector<vector<int>> e(sz,vector<int>(sz,0));

    int ni,ch;
    for(int i=0;i<h;i++){
      e[sz-2][i]=1;
    }
    for(int i=0;i<w;i++){
      cin >> ni;
      for(int j=0;j<ni;j++){
        cin >> ch;
        e[ch-1][50+i]=1;
      }
      e[50+i][100+i]=1;
    }
    for(int i=0;i<c;i++){
      cin >> ni;
      for(int j=0;j<ni;j++){
        cin >> ch;
        e[100+ch-1][150+i]=1;
      }
      e[150+i][200+i]=1;
    }
    for(int i=0;i<m;i++){
      cin >> ni;
      for(int j=0;j<ni;j++){
        cin >> ch;
        e[200+ch-1][250+i]=1;
      }
      e[250+i][sz-1]=1;
    }
    e[301][302]=nw;
    e[303][304]=nc;
    e[305][sz-1]=nm;
    for(int i=0;i<h;i++){
      e[i][301]=1;
    }
    for(int i=0;i<c;i++){
      e[302][150+i]=1;
    }
    for(int i=0;i<w;i++){
      e[100+i][303]=1;
    }
    for(int i=0;i<m;i++){
      e[304][250+i]=1;
    }
    for(int i=0;i<c;i++){
      e[200+i][305]=1;
    }

    // for(int i=0;i<sz;i++){
    //   for(int j=0;j<sz;j++){
    //     cout << e[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    FordFulkerson solver(e,sz-2,sz-1);
    cout << solver.solve() << endl;
  }
  return 0;
}

