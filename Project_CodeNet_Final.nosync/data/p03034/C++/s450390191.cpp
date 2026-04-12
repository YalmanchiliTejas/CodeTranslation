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

ll N;
ll S[200010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N;
  rep(i,N)cin>>S[i];

  ll res=0;
  repl(d,1,N-1){
    map<ll,bool> used;
    ll sum=0;
    for(ll l=0,r=N-1;l<N&&r>d;l+=d,r-=d){
      if(used[l]||used[r]||l==r)break;
      used[l]=used[r]=true;
      sum+=S[l]+S[r];
      maxch(res,sum);
    }
  }
  cout<<res<<endl;

  return 0;
}
