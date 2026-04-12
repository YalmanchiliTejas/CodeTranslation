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

int K;
ll dp[2][501][2][2];
ll sum[2][501][2][2];
vector<vector<int> > nxtst;

ll solve(string S){
  int N=S.size();
  memset(dp,0,sizeof(dp));
  memset(sum,0,sizeof(sum));

  int crtd=0,nxtd=1;
  rep(i,N){
    memset(dp[nxtd],0,sizeof(dp[nxtd]));
    memset(sum[nxtd],0,sizeof(sum[nxtd]));
    dp[crtd][0][!(i==0)][(i==N-1)]+=1;
    rep(j,K){
      rep(f1,2){
        rep(f2,2){
          int mn=(f2==0?1:0);
          int mx=(f1==0?S[i]-'0':9);
          repl(nxt,mn,mx+1){
            int nxtj=nxtst[j][nxt];
            (dp[nxtd][nxtj][(f1==0&&nxt==mx?0:1)][1]+=dp[crtd][j][f1][f2])%=mod;
            (sum[nxtd][nxtj][(f1==0&&nxt==mx?0:1)][1]+=sum[crtd][j][f1][f2])%=mod;
            if(nxtj==K-1){
              (sum[nxtd][nxtj][(f1==0&&nxt==mx?0:1)][1]+=dp[crtd][j][f1][f2])%=mod;
            }
          }
        }
      }
    }
    swap(crtd,nxtd);
  }

  ll res=0;
  rep(j,K){
    rep(f1,2){
      (res+=sum[crtd][j][f1][1])%=mod;
    }
  }

  return res;
}

string decrement(string A) {
  for(int i = A.size() - 1; i >= 0; --i) {
    if(A[i] > '0') {
      A[i]--;
      break;
    } else {
      A[i] = '9';
    }
  }
  if(A[0] == '0' && A.size() > 1) {
    return A.substr(1);
  } else {
    return A;
  }
}

int main(){
  string A,B,s;
  cin>>A>>B>>s;

  int N=s.size();
  vector<string> pfx;
  rep(i,N+1){
    pfx.push_back(s.substr(0,i));
  }
  sort(all(pfx));
  uni(pfx);
  K=pfx.size();
  nxtst=vector<vector<int> >(K,vector<int>(10,-1));
  rep(i,K){
    rep(nxt,10){
      string t=pfx[i];
      t+='0'+nxt;
      int idx=0;
      while(1){
        idx=lower_bound(all(pfx),t)-pfx.begin();
        if(idx<K&&pfx[idx]==t)break;
        t=t.substr(1);
      }
      nxtst[i][nxt]=idx;
    }
  }

  if(A!="0")cout<<(solve(B)-solve(decrement(A))+mod)%mod<<endl;
  else cout<<solve(B)%mod<<endl;

  return 0;
}

