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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dfs(ll a, ll b){
  if(a==0){
    if(b>0) return 1;
    return 0;
  }
  if(b<=(ll)pow(2, a+1)-2) return dfs(a-1, b-1);
  return (ll)pow(2, a) + dfs(a-1, b- pow(2, a+1) + 1);
}
  

int main(){
  ll N; ll X; cin >> N >> X;
  cout << dfs(N, X) << endl;
}

  