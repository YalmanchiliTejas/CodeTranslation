#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

ll val[60][100010];
ll to[60][100010];

int main(){
  ll n,x,m;
  cin >> n >> x >> m;
  rep(j,m){
    val[0][j]=j;
    to[0][j]=(ll)j*j%m;
  }
  rep(i,60-1)rep(j,m){
    val[i+1][j]=val[i][j]+val[i][to[i][j]];
    to[i+1][j]=to[i][to[i][j]];
  }
  ll next=x,ans=0;
  for(int i=60-1;i>=0;i--){
    if((n>>i)&1){
      ans+=val[i][next];
      next=to[i][next];
    }
  }
  cout << ans << endl;
}