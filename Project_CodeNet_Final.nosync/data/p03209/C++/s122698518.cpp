#include "bits/stdc++.h"
#include <string>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define int ll
//#define slld(t) scanf("%lld",&t)
//#define sd(t) scanf("%d",&t)
//#define pd(t) printf("%d\n",t)
//#define plld(t) printf("%lld\n",t)
#define vec vector < int >
#define vecp vector < pair < int , int > >
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define pii pair < int , int >
#define pll pair < ll , ll > 
#define debug(x)   cerr<<#x<<": "<<x<<endl
// #define mod  1000000007
#define N 100005
// #define MAX 200005
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcount
#define PI acos(-1)
//#define endl "\n"
// const int inf = (int)1e18 + 10;
const int mod = 1e9 + 7;

const int inf = 1e15;

int patt[55] , layer[55];
int get(int x , int k ){
  // cout << x << " " << k << endl;
  if(k >= layer[x])
    return patt[x];
  if(k == 0) return 0;
  int y = layer[x-1];
  int p = patt[x-1];
  if(k >= (y + 2))
    return p + 1 + get(x-1 , k - y- 2);
  else if(k == y + 1)
    return p;
  else
    return get(x-1 , k-1 );
}
signed main(){
  fast;
  
  int n , k;
  cin >> n >> k;

  patt[0] = 1;
  layer[0] = 1;
  for(int i= 1 ; i<=n ; i++){
       layer[i] = 2*layer[i-1] + 3;
       patt[i] = 2*patt[i-1] + 1;
  }

  int ans = get(n , k);
  cout << ans << endl;
  


}
