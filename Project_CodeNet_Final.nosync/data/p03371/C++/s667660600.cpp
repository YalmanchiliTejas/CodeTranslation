#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

int main(){
  ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;

  ll ans = 1e18;
  if((a + b) < 2*c){
    // 別々に買う
    ans = a * x + b * y;
    cout<<ans<<endl;
    return 0;
  }
  else{
    // min(x,y)*2 - max(x,y)*2のどれかをc買う
    for(ll i = min(x,y) * 2; i <= max(x,y) * 2; i++){
      ll tmp = 0;
      tmp += i * c;
      tmp += max( (x - (i / 2 ) ), (ll)0) * a;
      tmp += max( (y - (i / 2 ) ), (ll)0) * b;
      // cout<<i<<" "<<tmp<<endl;
      ans = min(ans , tmp);
    }
    cout<<ans<<endl;
    return 0;
  }
}
