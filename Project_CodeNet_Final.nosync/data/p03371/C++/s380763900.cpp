#include<time.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
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
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
using namespace std;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

template<typename ...Ts>
void show(Ts... ts){
  cout<<"#:";
  auto print=[](auto v){cout<<v<<" ";};
  initializer_list<int>{(void(print(ts)),0)...};
  cout<<endl;
}

int main(void){
    int a,b,c,x,y;
    int ans=1e9,alt;
    cin>>a>>b>>c>>x>>y;
    
    rep(i,max(x,y)*2+1){
        alt=i*c;
        alt+=max(0,(2*x-i+1)/2)*a;
        alt+=max(0,(2*y-i+1)/2)*b;
        ans=min(ans,alt);
    }
    
    cout<<ans;
}


