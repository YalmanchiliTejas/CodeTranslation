#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,m,n) for(ll i=m;i<(ll)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const ll mod= 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int n;
  cin>>n;
  int ans=800*n;
  ans-=n/15*200;
  cout<<ans<<endl;
  return 0;
  }