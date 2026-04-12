#include<iostream>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
#define ll  long long 
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
#define mod 1000000007
  vector<ll>to[1000005];
   ll dp[2000000];
 int gcd(int a, int b)
{
  if (a%b == 0)
{
return(b);
}
else
{
return(gcd(b,a%b));
}
}
  vector<vector<bool>>d(5001,vector<bool>(5001));
int main(){
  ll a,b,x,c,y;cin>>a>>b>>c>>x>>y;
  ll ans=0,z=x;
  if(a+b>c*2)ans+=min(x,y)*c*2;
  else ans+=min(x,y)*(a+b);
  x=max((ll)0,x-y);
  y=max(y-z,(ll)0);
  if(y==0){
    if(a>c*2)ans+=x*2*c;
    else ans+=x*a;
  }
  else
  {
    if(b>c*2)ans+=y*2*c;
    else ans+=y*b;
  }
  cout<<ans;
}

