#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <ctime>
#include <list>
#include <numeric>
#include <utility>
#include <ctime>
#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=true;

/*---------------------------------------------------*/

int main(){
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  ll cnt=1;
  if(k==0){
    cout<<n*n<<endl;
    return 0;
  }
  for(int i=k+1;i<=n;i++){
    //cout<<i<<" -> "<<((n-i+1)/i*cnt+cnt)<<" "<<max(0,(n-i+1)%i-k)<<" "<<cnt<<endl;
    ans+=((n-i+1)/i*cnt+cnt)+max(ll(0),(n-i+1)%i-k);
    cnt++;
  }
  cout<<ans<<endl;
  return 0;
}
