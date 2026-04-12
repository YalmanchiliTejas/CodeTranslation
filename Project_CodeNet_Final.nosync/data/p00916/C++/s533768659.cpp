#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  while(1){
    int n;
    cin >> n;
    if(n==0) return 0;
    vector<int> l(n),t(n),r(n),b(n);
    map<int,int> xmp,ymp;
    rep(i,n){
      cin >> l[i] >> t[i] >> r[i] >> b[i];
      xmp[l[i]-1]=-1;
      xmp[l[i]]=-1;
      xmp[r[i]-1]=-1;
      xmp[r[i]]=-1;
      ymp[b[i]-1]=-1;
      ymp[b[i]]=-1;
      ymp[t[i]-1]=-1;
      ymp[t[i]]=-1;
    }
    int xsz=0,ysz=0;
    for(auto &p:xmp) p.second=(xsz++);
    for(auto &p:ymp) p.second=(ysz++);
    vector<vector<LL>> f(xsz,vector<LL>(ysz,0));
    rep(i,n){
      int ld = xmp[l[i]];
      int rd = xmp[r[i]];
      int td = ymp[t[i]];
      int bd = ymp[b[i]];
      repp(x,ld,rd){
        repp(y,bd,td){
          f[x][y]|=(1LL<<i);
        }
      }
    }
    // rep(i,xsz){
    //   rep(j,ysz){
    //     cout << f[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    set<LL> st;
    int count=0;
    queue<pair<int,int>> q;
    vector<int> v={0,1,0,-1,0};
    rep(i,xsz){
      rep(j,ysz){
        if(f[i][j]>-1){
          count++;
          LL cc = f[i][j];
          f[i][j]=-1;
          q.push({i,j});
          while(!q.empty()){
            auto p = q.front();
            q.pop();
            rep(k,4){
              int nx = p.first+v[k];
              int ny = p.second+v[k+1];
              if(0<=nx&&nx<xsz&&0<=ny&&ny<ysz){
                if(f[nx][ny]==cc){
                  f[nx][ny]=-1;
                  q.push({nx,ny});
                }
              }
            }
          }
        }
      }
    }
    cout << count << endl;
  }
  return 0;
}

