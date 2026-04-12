#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>
#include<unordered_set>
#include<unordered_map>
 
#define pi 3.141592653
#define in freopen("entrada","r",stdin);
#define out freopen("myfile.txt","w",stdout);
#define ii pair<int,int> 
#define fast_io cin.tie(0), cin.sync_with_stdio(false);
#define inf 0x3f3f3f3f
#define sup_inf 1e18
#define f first
#define s second
#define eps 1e-9

#define nl ( no << 1)
#define nr ( no << 1)|1
#define mid l+(( r-l)>>1)
 
using namespace std;
typedef long long ll;	
typedef long double ld;
typedef unsigned long long ull;
typedef  pair< long long , pair< int,int> > iii;

const int maxn = 2e5 + 100; 
const int MAX = 1010;
const int mod = 1e9 + 7;
const int MAXLV = 16;
 

using namespace std;



int a[maxn];


int n;




ll sub( ll a, ll b) {
  a-=b;
  if ( a < 0 )a = mod + a;
  return a;
}

ll sum ( ll a, ll b ){
  return ( a+ b )  % mod ;
}

int main () {
  
  //~ in
  
  fast_io
  
  cin >> n;
  
  
  
  ll tot = 0;
  
  for(int i = 0 ;i < n;i++ ){ 
    cin >> a[i];
    tot  = sum  ( tot, a[i] );
  }
  
  ll ans = 0;
  for(int i = 0 ;i < n;i++) { 
    tot = sub ( tot , a[i] );
    ans = sum ( ans, ( a[i] * tot) % mod ) % mod;
  }
  
  cout << ans << '\n';
  
  
  
  
  
  
  return 0;
}





