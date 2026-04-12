#include "bits/stdc++.h"
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
#define mod  1000000007
#define N   200005
#define MAX 300005
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcountll
#define PI acos(-1)
//#define endl "\n"
#define inf 1e+15
multiset <int > s;
signed main(){
  fast;
  int n; cin >> n;
  int x;
  for(int i = 1 ; i<= n ; i++){
  	   cin >> x;
  	   auto it = s.upper_bound(x-1);
  	   if(it == s.begin()){
  	      s.insert(x);
  	      continue;
  	   }
       else 
  	     it--;

  	  s.erase(it);
  	  s.insert(x);

  }

  cout << s.size() << endl;


}
  
