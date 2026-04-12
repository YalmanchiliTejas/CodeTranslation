#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<int,int> pint;
const int inf   = 1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


ll sum(ll m,ll k){
  ll mod=(k+1)%m;
  ll num=(k+1)/m;
  ll ret=num*(num-1)*m/2;
  ret+=mod*num;
  return ret;
  }

int main(){
  ll n,k;
  cin>>n>>k;
  if(k==0){cout<<n*n<<endl; return 0;}
  ll ans=0;
  for(ll i=k+1;i<=n;i++){
    ans+=sum(i,n+i-k)-sum(i,n);
    }
  cout<<ans<<endl;    
  return 0;
  }