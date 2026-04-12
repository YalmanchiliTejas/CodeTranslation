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

string S;
int D;
ll dp[2][101][2];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>S>>D;
  int N=S.size();
  dp[0][0][0]=1;
  int crt=0,nxt=1;
  rep(i,N){
    memset(dp[nxt],0,sizeof(dp[nxt]));
    rep(r,D)rep(f,2){
      rep(d,(f==0?S[i]-'0'+1:10)){
        (dp[nxt][(r+d)%D][!(f==0&&d==(S[i]-'0'))]+=dp[crt][r][f])%=mod;
      }
    }
    swap(crt,nxt);
  }
  cout<<(dp[crt][0][0]+dp[crt][0][1]+mod-1)%mod<<endl;

  return 0;
}
