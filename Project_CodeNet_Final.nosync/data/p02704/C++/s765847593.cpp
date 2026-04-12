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
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

bool solve(ll N,const vector<ull>& R,const vector<ull>& bR,const vector<ull>& C,const vector<ull>& bC,vector<vector<ull>>& ans){
  rep(i,N)rep(j,N)ans[i][j]=2;
  ll rcnt=N,ccnt=N;
  rep(i,N){
    if(R[i]==0&&bR[i]==1){
      rcnt--;
      rep(j,N)ans[i][j]=1;
    }else if(R[i]==1&&bR[i]==0){
      rcnt--;
      rep(j,N)ans[i][j]=0;
    }
  }
  rep(j,N){
    if(C[j]==0&&bC[j]==1){
      ccnt--;
      rep(i,N){
        if(ans[i][j]!=2&&ans[i][j]!=1)return false;
        ans[i][j]=1;
      }
    }else if(C[j]==1&&bC[j]==0){
      ccnt--;
      rep(i,N){
        if(ans[i][j]!=2&&ans[i][j]!=0)return false;
        ans[i][j]=0;
      }
    }
  }

  if(rcnt>=2&&ccnt>=2){
    ll crti=0;
    rep(i,N){
      if(R[i]!=bR[i])continue;
      ll crtj=0;
      rep(j,N){
        if(C[j]!=bC[j])continue;
        if(ans[i][j]==2){
          ans[i][j]=(crti+crtj)%2;
        }
        crtj++;
      }
      crti++;
    }
  }else if(rcnt==0||ccnt==0){

  }else if(rcnt==1){
    ull ridx=0;
    rep(i,N){
      if(R[i]==bR[i])ridx=i;
    }
    rep(j,N){
      if(C[j]!=bC[j])continue;
      ull v=2;
      rep(i,N){
        if(ans[i][j]==2)continue;
        if(C[j]==0){
          if(v==2) v=ans[i][j];
          else v&=ans[i][j];
        }else{
          if(v==2) v=ans[i][j];
          else v|=ans[i][j];
        }
      }
      if(bC[j]!=v) ans[ridx][j]=bC[j];
      else ans[ridx][j]=bR[ridx];
    }
  }else if(ccnt==1){
    ull cidx=0;
    rep(j,N){
      if(C[j]==bC[j])cidx=j;
    }
    rep(i,N){
      if(R[i]!=bR[i])continue;
      ull v=2;
      rep(j,N){
        if(ans[i][j]==2)continue;
        if(R[j]==0){
          if(v==2) v=ans[i][j];
          else v&=ans[i][j];
        }else{
          if(v==2) v=ans[i][j];
          else v|=ans[i][j];
        }
      }
      if(bR[i]!=v) ans[i][cidx]=bR[i];
      else ans[i][cidx]=bC[cidx];
    }
  }else{
    assert(false);
  }

  /*rep(i,N){
    rep(j,N){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }*/

  // check
  rep(i,N){
    ull v=ans[i][0];
    repl(j,1,N){
      if(R[i]==0)v&=ans[i][j];
      else v|=ans[i][j];
    }
    if(bR[i]!=v)return false;
  }
  rep(j,N){
    ull v=ans[0][j];
    repl(i,1,N){
      if(C[j]==0)v&=ans[i][j];
      else v|=ans[i][j];
    }
    if(bC[j]!=v)return false;
  }

  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin>>N;
  vector<ull> S(N),T(N),U(N),V(N);
  rep(i,N){
    cin>>S[i];
  }
  rep(i,N){
    cin>>T[i];
  }
  rep(i,N){
    cin>>U[i];
  }
  rep(i,N){
    cin>>V[i];
  }

  const ll B=64;
  vector<vector<ull>> ans(N,vector<ull>(N));
  bool ok=true;
  rep(b,B){
    vector<ull> bU(N), bV(N);
    vector<vector<ull>> res(N,vector<ull>(N));
    rep(i,N){
      bU[i]=(U[i]>>(ull)b)&1ULL;
    }
    rep(i,N){
      bV[i]=(V[i]>>(ull)b)&1ULL;
    }
    ok=solve(N,S,bU,T,bV,res);
    if(!ok)break;
    rep(i,N)rep(j,N)ans[i][j]|=(res[i][j]<<(ull)b);
  }

  if(!ok)cout<<-1<<"\n";
  else{
    rep(i,N){
      rep(j,N)cout<<ans[i][j]<<" ";
      cout<<"\n";
    }
  }

  return 0;
}
