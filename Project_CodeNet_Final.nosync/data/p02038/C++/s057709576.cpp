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

bool c(char c){
  if(c=='T')return true;
  else return false;
}

bool f(bool x,bool y){
  if(x&&!y)return false;
  else return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  bool x;
  {
    char a;
    cin>>a;
    x=c(a);
  }
  rep(i,n-1){
    char a;
    cin>>a;
    bool y=c(a);
    x=f(x,y);
  }
  if(x)cout<<"T"<<endl;
  else cout<<"F"<<endl;

  return 0;
}

