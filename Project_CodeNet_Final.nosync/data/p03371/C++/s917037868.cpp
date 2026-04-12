#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef string S;
typedef queue<int> qi;
typedef pair<ll,ll> P;
typedef vector<P> vp;
struct edge{ ll to, cost; };//　一つ目は結んでいるノード,二つ目はその辺の重みを指す
//#define sort(a) sort(a.begin(),a.end())
using Graph = vector<vector<edge>>;  //隣接リスト
#define reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define elif else if
#define unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mp make_pair
#define fr(i,n)for(ll i=0;i<(n);i++)
#define ifr(i,n)for(ll i=(n)-1;i>=0;i--)
#define ALL(a) (a).begin(),(a).end()
const int MOD = 1e9+7;
const ll INF =1e18;


int main(){
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  ll ans = 0;
  if(a+b<2*c){
    ans += a*x + b*y;
  }else{
    if(x>y){
      if(2*c>a)ans += c*2*y+a*(x-y);
      else ans += c*2*x;
    }else{
      if(2*c>b)ans+=c*2*x+b*(y-x);
      else ans += c*2*y;
    }
  }
  cout << ans << endl;
}