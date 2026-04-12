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

ll n,k;

int main(){
  cin>>n>>k;
  if(k==0){
    cout<<n*n<<endl;
    return 0;
  }
  ll cnt=0;
  repl(b,k+1,n+1){
    for(ll p=0;p<n;p+=b){
      ll q=p+b;
      if(q>n){
        ll r=n-p;
        cnt+=max(0LL,r-k+1);
      }else{
        ll r=q-p-1;
        cnt+=max(0LL,r-k+1);
      }
    }
  }
  cout<<cnt<<endl;
  return 0;
}
